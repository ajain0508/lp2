#include <bits/stdc++.h>
using namespace std;

vector<string> greetings = {"Hello!", "Hi!", "Hey there!", "Greetings!", "Nice to see you!"};
vector<string> goodbyes = {"Goodbye!", "See you later!", "Bye!", "Take care!"};
vector<string> help_responses = {"How may I assist you?", "What can I do for you?", "How can I help?"};
vector<string> problem_responses = {"I'm sorry to hear that. Can you please tell me more about the problem?", "Let me see if I can help. What seems to be the issue?", "I'll do my best to help you. What's the problem?"};
vector<string> thankyou_responses = {"You are welcome!", "No problem!", "It was my pleasure!", "Glad to help!"};

string getRandomResponse(vector<string>& responses) {
    int index = rand() % responses.size();
    return responses[index];
}

void chatbot() {
    while (true) {
        string user_input;
        cout << "User: ";
        getline(cin, user_input);
        if (user_input.find("hello") != string::npos || user_input.find("hi") != string::npos || user_input.find("hey") != string::npos) {
            cout << "Chatbot: " << getRandomResponse(greetings) << endl;
        } 
        else if (user_input.find("bye") != string::npos || user_input.find("goodbye") != string::npos || user_input.find("see you") != string::npos) {
            cout << "Chatbot: " << getRandomResponse(goodbyes) << endl;
            break;
        } 
        else if (user_input.find("help") != string::npos || user_input.find("support") != string::npos) {
            cout << "Chatbot: " << getRandomResponse(help_responses) << endl;
        } 
        else if (user_input.find("problem") != string::npos || user_input.find("issue") != string::npos || user_input.find("error") != string::npos) {
            cout << "Chatbot: " << getRandomResponse(problem_responses) << endl;
        } 
        else if (user_input.find("thank you") != string::npos || user_input.find("thanks") != string::npos || user_input.find("thankyou") != string::npos) {
            cout << "Chatbot: " << getRandomResponse(thankyou_responses) << endl;
        } 
        else {
            cout << "Chatbot: I'm sorry, I don't understand. Can you please rephrase your request?" << endl;
        }
    }
}

int main() {
    chatbot();
    return 0;
}
