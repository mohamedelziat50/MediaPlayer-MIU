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
    if (isCurrentEmpty() || isEmpty())
        return nullptr;

    current = current->next;
    return current->videoPath;
}

String^ VideoList::getCurrentVideo()
{
    return isCurrentEmpty() ? nullptr : current->videoPath;
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

//When you click on a video path in the gui, it becomes the current node
void VideoList::setCurrentNode(String^ videoPath)
{
    if (isEmpty())
        return;

    Node^ temp = head;
    do
    {
        if (temp->videoPath == videoPath)
        {
            current = temp;
            return;
        }
        temp = temp->next;
    } while (temp != head);
}

void VideoList::shuffle()
{
    int listSize = getSize();
    if (listSize == 1 || listSize == 0)
    {
        return;
    }

    srand(time(0));

    // Generate a random index between 0 and listSize - 1
    int randomIndex = rand() % listSize;

    // Traverse to the random index
    Node^ temp = head;
    for (int i = 0; i < randomIndex; i++)
    {
        temp = temp->next;
    }

    current = temp;
}