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
        Node^ next;
        Node^ prev;
        /*
        ^ is a "handle operator".It manages references to objects that are garbage - collected by the.NET runtime
        ^ is used instead of pointers for objects in the managed heap section(which are automtically garbage collected)
       */
       Node(String^ path) : videoPath(path), next(nullptr), prev(nullptr) {}
    };

    Node^ head; // Points to the first node
    Node^ current; // Points to the currently playing node
    Node^ tail;   // Points to the node before head

public:
    // Constructor
    VideoList();

    // No Need For A Destructor As Managed Data Types Are Automatically Cleaned

    // Add a video path to the list
    void addVideo(String^ videoPath);

    // Move to the next video
    String^ nextVideo();

    // Move to the previous video
    String^ prevVideo();

    // Get the current video
    String^ getCurrentVideo();

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

    void setCurrentNode(String^ videoPath);

    void shuffle();
};

