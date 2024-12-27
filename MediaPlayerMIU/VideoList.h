#pragma once
#include <iostream>
#include <assert.h>

using namespace std;
using namespace System;

/*-- VideoList.h -------------------------------------------------------------

This header file defines a VideoList Class: Circular Doubly LL

Constructor: Constructs an empty VideoList object

addVideo: Add a video path to the list

nextVideo: Move to the next video

prevVideo: Move to the previous video

getCurrentVideo: Get the current video

isEmpty: Check if the list is empty

printList: Print all video paths in the list
getSize: Gets the VideoList's size

getCurrentNodeIndex: Gets the curret Node's index

---------------------------------------------------------------------------*/

ref class VideoList
/*

A ref class defines a managed type that operates in the .NET managed environment. Whereas, standard C++ class operates in the native runtime environment.

ref class automatically collects garbage --no need to manually delete objects

managed types can only hold other managed types (const is not supported, because .NET does not have an equivalent to C++'s const for methods)

ref class is used if the class will directly interact with .NET components (if it will be integerated in the .NET). If it was a helper class, it could've been a standard c++ class

*/
{

private:
    // Private Node structure for the linked list
    //ref class must contain ref types
    ref struct Node
    {
        String^ videoPath; //type of string that .NET can understand
        String^ videoName; // Added this to be used to populate tracklist dynamically
        Node^ next;
        Node^ prev;
        //int duration 
        /*
        ^ is a "handle operator".It manages references to objects that are garbage - collected by the.NET runtime
        ^ is used instead of pointers for objects in the managed heap section(which are automtically garbage collected)
       */
       Node(String^ path) : videoPath(path), next(nullptr), prev(nullptr) {}
       Node(String^ path, String^ name): videoPath(path), videoName(name), next(nullptr), prev(nullptr) {}
    };

    Node^ head; // Points to the first node
    Node^ current; // Points to the currently playing node
    Node^ tail;   // Points to the node before head

public:
    // Constructor
    VideoList();

    // No Need For A Destructor As Managed Data Types Are Automatically Cleaned

    // Add a video path to the list
    void addVideo(String^ videoPath, System::Windows::Forms::ListBox^ track_list);

    // Add a video path and it's name to the list
    void addVideo(String^ videoPath, String^ videoName, System::Windows::Forms::ListBox^ track_list);

    // Move to the next video
    String^ nextVideo();

    // Move to the previous video
    String^ prevVideo();

    // Get the current video's path (Current Node)
    String^ getCurrentNodePath();

    // Get the current video's name (Current Node)
    String^ getCurrentNodeName();

    // Set the current video through an index(Current Node)
    void setCurrentNode(int index);

    // Added a function that's gets a specific video node through it's index.
    Node^ VideoList::getVideoAt(int index);

    // Check if the list is empty
    bool isEmpty();

    // Check if the current node is empty
    bool isCurrentEmpty();

    // Print all video paths in the list
    void printList();

    // Get the current list's size
    int getSize();

    // Get the curret index of the node.
    int getCurrentNodeIndex();

    // Added a function to populate tracklist and to mantain encapsulation of the "Node" private member
    void populateTrackList(System::Windows::Forms::ListBox^ track_list);

    // This function set's the current node to be at a random index.
    int shuffle();

    //function to remove a video from the linked list
    void removeVideo(System::Windows::Forms::ListBox^ track_list);

    //function to save the videolist in a file after every add and every remove
    void  saveToFile(String^ filename, System::Windows::Forms::ListBox^ track_list);

    //function to load the videos that were imported previously to the list
    void loadFromFile(String^ filename, System::Windows::Forms::ListBox^ track_list);

    //just for handling an error
    bool isFileLocked();

    void arrangeAlphabetically(VideoList^ videoList, System::Windows::Forms::ListBox^ track_list);

    int split(System::Collections::Generic::List<System::String^>^ videoPaths, System::Collections::Generic::List<int>^ videoDurations, int low, int high);

    void quickSort(System::Collections::Generic::List<System::String^>^ videoPaths, System::Collections::Generic::List<int>^ videoDurations, int low, int high);
};

