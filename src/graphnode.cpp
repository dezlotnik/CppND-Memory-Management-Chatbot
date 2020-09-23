#include "graphedge.h"
#include "graphnode.h"
#include <iostream>
#include <memory>

GraphNode::GraphNode(int id)
{
    std::cout<<"GraphNode "<< id << " Constructor"<<"\n";
    _id = id;
}

GraphNode::~GraphNode()
{
    //// STUDENT CODE
    ////
    std::cout<<"GraphNode " << _id << " Destructor"<<"\n";
    // ChatLogic allocated chatbot memory and Chatlogic will deallocate
    // memory in its destructor. Do not deallocate chatbot here.
    // delete _chatBot;

    ////
    //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges.push_back(edge);
}

void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge)
{
    _childEdges.push_back(std::move(edge));
}

//// STUDENT CODE
////
void GraphNode::MoveChatbotHere(ChatBot chatBot)
{
    _chatBot = std::move(chatBot);
    _chatBot.SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    newNode->MoveChatbotHere(std::move(_chatBot));
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////

    return _childEdges[index].get();

    ////
    //// EOF STUDENT CODE
}