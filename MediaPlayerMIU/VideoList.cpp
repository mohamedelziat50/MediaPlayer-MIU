#include "VideoList.h"
#include "time.h"

// Consruct an empty VideoList object
VideoList::VideoList() : head(nullptr), current(nullptr) {} // Intialize to null

// Function to check whether the list is empty.
bool VideoList::isEmpty()
{
    return head ? false : true;
}

// Check if the current node is empty
bool VideoList::isCurrentEmpty()
{
    return current ? false : true;
}

// Function to add a video to the list
void VideoList::addVideo(String^ videoPath)
{
    // Create new node object that takes in the video path.
    Node^ newNode = gcnew Node(videoPath);
    assert(newNode != nullptr);

    if (isEmpty())
    {
        // First insertion will be the head.
        head = newNode;
        tail = newNode;
        // Since it's circular + doubly, need to wrap around always!
        newNode->next = newNode;
        newNode->prev = newNode;

        // Set the current Node to be the current playing video.
        // current = head; CURRENT SHOULD BE USED IN THE GUI 
        //Want to make it so that the selected video is the current one. How?
    }
    else
    {
        // Set the new inserted node to be the current tail's next
        tail->next = newNode;

        // Pointers to mantain doubly circular l.l
        newNode->prev = tail;
        newNode->next = head;

        // Set also the new tail for the head
        head->prev = newNode;
        tail = newNode; // Update tail
    }
}

// Add a video path and it's name to the list (OVER-LOADED FUNCTION)
void  VideoList::addVideo(String^ videoPath, String^ videoName)
{
    // Create new node object that takes in the video path.
    Node^ newNode = gcnew Node(videoPath, videoName);
    assert(newNode != nullptr);

    if (isEmpty())
    {
        // First insertion will be the head.
        head = newNode;
        tail = newNode;
        // Since it's circular + doubly, need to wrap around always!
        newNode->next = newNode;
        newNode->prev = newNode;

        // Set the current Node to be the current playing video.
        // current = head; CURRENT SHOULD BE USED IN THE GUI 
        //Want to make it so that the selected video is the current one. How?
    }
    else
    {
        // Set the new inserted node to be the current tail's next
        tail->next = newNode;

        // Pointers to mantain doubly circular l.l
        newNode->prev = tail;
        newNode->next = head;

        // Set also the new tail for the head
        head->prev = newNode;
        tail = newNode; // Update tail
    }
}

// Function that switches the current node to the previous
String^ VideoList::prevVideo()
{
    // If there's no current video return
    if (isCurrentEmpty() || isEmpty())
        return nullptr;


    current = current->prev;
    return current->videoPath;
}

// Function that switches the current node to the next
String^ VideoList::nextVideo()
{
    // If there's no current video return
    if (isCurrentEmpty() || isEmpty()||current->next==nullptr)
        return nullptr;

    current = current->next;
    return current->videoPath;
}

void VideoList::printList()
{
    if (isEmpty())
        return;

    // Traverse the list
    Node^ temp = head;
    do
    {
        Console::WriteLine(temp->videoPath); // Managed Console output
        temp = temp->next;
    } while (temp != head);
}

// Most probably will be a member variable later -> to be reviewed
int VideoList::getSize()
{
    if (isEmpty())
        return 0; // List is empty

    int size = 0;
    Node^ temp = head;
    do {
        size++;
        temp = temp->next;
    } while (temp != head); // Loop until we reach the head again

    return size;
}

int VideoList::getCurrentNodeIndex()
{
    if (isCurrentEmpty() || isEmpty())
        return -1; // Indicates the list is empty or current is not set

    int index = 0;

    Node^ temp = head;

    // Traverse the list and find the index of the current node
    do
    {
        if (temp == current)
            return index;

        index++;
        temp = temp->next;
    } while (temp != head); // Loop until we reach the head again

    return -1; // In case the current node is not found, which should not happen in normal conditions
}

// Get the current video's path (Current Node)
String^ VideoList::getCurrentNodePath()
{
    return isCurrentEmpty() ? nullptr : current->videoPath;
}

// Get the current video's name (Current Node)
String^ VideoList::getCurrentNodeName()
{
    return isCurrentEmpty() ? nullptr : current->videoName;
}

//When you click on a video path in the gui, it becomes the current node
void VideoList::setCurrentNode(int index)
{
    if (index < 0 || index >= getSize())
        return;

    Node^ temp = head;

    for (int i = 0; i < index; i++)
        temp = temp->next;
    
    current = temp;
}




// Added a function that's gets a specific video node through it's index.
VideoList::Node^ VideoList::getVideoAt(int index)
{
    if (index < 0 || index >= getSize())
        return nullptr;

    Node^ temp = head;
    for (int i = 0; i < index; i++)
    {
        temp = temp->next;
    }
    return temp;
}

// Added a function to populate tracklist and to mantain encapsulation of the "Node" private member
void VideoList::populateTrackList(System::Windows::Forms::ListBox^ track_list)
{
    if (isEmpty() || track_list == nullptr)
        return;

    // Clear the existing items in the track list
    track_list->Items->Clear(); 

    Node^ temp = head;

    do
    {
        // Add the video name to the track list
        track_list->Items->Add(temp->videoName);
        temp = temp->next;
    } 
    while (temp != head); // Continue until we loop back to the head
}

// This function set's the current node to be at a random index.
int VideoList::shuffle()
{
    // Get the list's size
    int listSize = getSize();

    // Condition to check whether shuffle is redundant
    if (isEmpty() || listSize == 1)
        return -1;

    // Set the size to generate random indexes
    srand(time(0));

    // Get the current Node's index
    int index = getCurrentNodeIndex();
    
    // Generate a random index between 0 and listSize - 1
    int randomIndex = rand() % listSize;

    // Traverse to the random index
    Node^ temp = head;
    for (int i = 0; i < randomIndex; i++)
        temp = temp->next;
    
    // Set the current node to be the new random index node
    current = temp;

    // To be used with selectedindexchanged
    return randomIndex;
}

void VideoList::removeVideo(System::Windows::Forms::ListBox^ track_list) {
    if (isEmpty() || track_list == nullptr || isCurrentEmpty())
        return;

    if (head == current) {
        head = current->next;
    }
    if (tail == current) {
        tail = current->prev;
    }
    if (head == current && tail == current) { // If there's only one node
        head = nullptr;
        tail = nullptr;
    }
    else {
        Node^ prevNode = current->prev;
        Node^ nextNode = current->next;

        nextNode->prev = prevNode;
        prevNode->next = nextNode;
    }

    delete current;
    current = head; // Set current to the new head (or nullptr if the list is empty)

    if (head == nullptr) { // Update the GUI track list if the list is now empty
        track_list->Items->Clear();
    }
    else {
        populateTrackList(track_list); // Refresh the track list
    }
}

