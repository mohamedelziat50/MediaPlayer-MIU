#include "VideoList.h"
#include "time.h"
#include <algorithm>
using namespace System;
using namespace System::IO;

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
void VideoList::addVideo(String^ videoPath, System::Windows::Forms::ListBox^ track_list)
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
    if (!isFileLocked())
    {
        saveToFile("data.dat",track_list);
    }
    else
    {
        Console::WriteLine("The file is locked by another process.");
    }

}

// Add a video path and it's name to the list (OVER-LOADED FUNCTION)
void  VideoList::addVideo(String^ videoPath, String^ videoName, System::Windows::Forms::ListBox^ track_list)
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

    if (!isFileLocked())
    {
        saveToFile("data.dat", track_list);
    }
    else
    {
        Console::WriteLine("The file is locked by another process.");
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

    if (!isFileLocked())
    {
        saveToFile("data.dat", track_list);
    }
    else
    {
        Console::WriteLine("The file is locked by another process.");
    }

}

void VideoList::saveToFile(String^ filePath, System::Windows::Forms::ListBox^ track_list)
{
    FileStream^ fileStream = nullptr;

    try
    {
        // Open or create the file with shared read access
        fileStream = gcnew FileStream(filePath, FileMode::OpenOrCreate, FileAccess::Write, FileShare::Read);

        BinaryWriter^ writer = gcnew BinaryWriter(fileStream);

        // Write the size of the list (number of videos)
        writer->Write(getSize());

        // If the list is not empty, write each video to the file
        if (!isEmpty())
        {
            Node^ temp = head;
            do
            {
                writer->Write(temp->videoName); // Write video name
                writer->Write(temp->videoPath); // Write video path
                temp = temp->next;
            } while (temp != head);
        }
    }
    finally
    {
        if (fileStream != nullptr)
            fileStream->Close(); // Ensure file is always closed
    }
    populateTrackList(track_list);
}


void VideoList::loadFromFile(String^ filePath, System::Windows::Forms::ListBox^ track_list)
{
    if (!File::Exists(filePath))
        return; // Do nothing if the file doesn't exist

    FileStream^ fileStream = nullptr;

    try
    {
        // Open the file with shared read access
        fileStream = gcnew FileStream(filePath, FileMode::Open, FileAccess::Read, FileShare::Read);

        BinaryReader^ reader = gcnew BinaryReader(fileStream);

        // Read the number of videos in the list
        int videoCount = reader->ReadInt32();

        // Clear the current list
        head = nullptr;
        tail = nullptr;
        current = nullptr;

        // Read and add each video to the list
        for (int i = 0; i < videoCount; i++)
        {
            String^ videoName = reader->ReadString();
            String^ videoPath = reader->ReadString();
            addVideo(videoPath, videoName,track_list);
        }
    }
    finally
    {
        if (fileStream != nullptr)
            fileStream->Close(); // Ensure file is always closed
    }
    populateTrackList(track_list);
}

bool VideoList::isFileLocked()
{
    try
    {
        FileStream^ fs = gcnew FileStream("data.dat", FileMode::Open, FileAccess::Read, FileShare::None);
        fs->Close();
        return false; // File is not locked
    }
    catch (IOException^)
    {
        return true; // File is locked
    }
}

void VideoList::arrangeAlphabetically(VideoList^ videoList, System::Windows::Forms::ListBox^ track_list)
{
    // Step 1: Collect all video names and paths into separate lists
    System::Collections::Generic::List<System::String^>^ videoNames = gcnew System::Collections::Generic::List<System::String^>();
    System::Collections::Generic::List<System::String^>^ videoPaths = gcnew System::Collections::Generic::List<System::String^>();

    Node^ current = head; // Start from the head of the linked list

    if (current != nullptr) { // If the list is not empty
        do {
            videoNames->Add(current->videoName);  // Add video name to the list
            videoPaths->Add(current->videoPath);  // Add video path to the list
            current = current->next;  // Move to the next node
        } while (current != head);  // Stop when we loop back to the head
    }

    // Step 2: Sort the video names along with their corresponding paths (Bubble Sort)
    for (int i = 0; i < videoNames->Count - 1; i++) {
        for (int j = 0; j < videoNames->Count - i - 1; j++) {
            if (System::String::Compare(videoNames[j], videoNames[j + 1]) > 0) { // Compare names alphabetically
                // Swap video names
                System::String^ tempName = videoNames[j];
                videoNames[j] = videoNames[j + 1];
                videoNames[j + 1] = tempName;

                // Swap corresponding paths
                System::String^ tempPath = videoPaths[j];
                videoPaths[j] = videoPaths[j + 1];
                videoPaths[j + 1] = tempPath;
            }
        }
    }

    // Step 3: Update the linked list with the sorted names and paths
    current = head; // Start from the head
    int index = 0;

    if (current != nullptr) {
        do {
            // Update the video name and path for each node
            current->videoName = videoNames[index];
            current->videoPath = videoPaths[index];
            current = current->next;  // Move to the next node
            index++;
        } while (current != head);  // Loop back to the head
    }

    // Step 4: Update the GUI track list
    videoList->populateTrackList(track_list);
    saveToFile("data.dat", track_list);
}



int VideoList::split(System::Collections::Generic::List<System::String^>^ videoPaths,
    System::Collections::Generic::List<int>^ videoDurations,
    int low, int high) {
    int pivot = videoDurations[low];  // First element is the pivot
    System::String^ pivotPath = videoPaths[low];  // Corresponding video path

    int left = low + 1;  // Start from the element right after the pivot
    int right = high;  //last element

    while (true) {
        while (left <= right && videoDurations[left] <= pivot) {
            left++; //move left variable to right if it is smaller than pivot
        }

        while (left <= right && videoDurations[right] > pivot) {
            right--; // Move right variable to the left if it is larger than pivot
        }


        if (left > right) {
            break;
        }

        // Swap the elements
        int tempDuration = videoDurations[left];
        videoDurations[left] = videoDurations[right];
        videoDurations[right] = tempDuration;

        System::String^ tempPath = videoPaths[left];
        videoPaths[left] = videoPaths[right];
        videoPaths[right] = tempPath;
    }

    //Swap the pivot with element at the right index
    int tempDuration = videoDurations[low]; //holding pivot
    videoDurations[low] = videoDurations[right]; //switch pivot with right, which is currently at mid index
    videoDurations[right] = tempDuration;

    System::String^ tempPath = videoPaths[low];
    videoPaths[low] = videoPaths[right];
    videoPaths[right] = tempPath;

    return right; //index where pivot is located
}

void VideoList::quickSort(System::Collections::Generic::List<System::String^>^ videoPaths, System::Collections::Generic::List<int>^ videoDurations, int low, int high)
{
    if (low < high) {
        // pivot
        int pivot = split(videoPaths, videoDurations, low, high);

        // Recursively sort elements before and after partition
        quickSort(videoPaths, videoDurations, low, pivot - 1);
        quickSort(videoPaths, videoDurations, pivot + 1, high);
    }
}


