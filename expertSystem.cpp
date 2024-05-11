#include <bits/stdc++.h>

using namespace std;

vector<string> symptoms = {"Fever", "Cough", "Headache", "Sore throat"};

unordered_map<string, vector<string>> diseases = {
    {"Common Cold", {"Fever", "Cough", "Headache", "Sore throat"}},
    {"Flu", {"Fever", "Headache"}},
    {"Strep Throat", {"Fever", "Sore throat"}},
    {"Migraine", {"Headache"}}
};

vector<string> get_user_input(){
    vector<string> user_symptoms;
    for (auto symptom : symptoms) {
        char response;
        cout << "Do you have " << symptom << "? (y/n): ";
        cin >> response;
        if (tolower(response) == 'y') {
            user_symptoms.push_back(symptom);
        }
    }
    return user_symptoms;
}

void diagnose() {
    vector<string> user_symptoms = get_user_input();
    vector<string> possible_diseases;

    for (auto disease : diseases) {
        for (auto symptom : disease.second) {
            if (find(user_symptoms.begin(), user_symptoms.end(), symptom) != user_symptoms.end()) {
                possible_diseases.push_back(disease.first);
                break;
            }
        }
    }

    if (!possible_diseases.empty()) {
        cout << "Possible diseases:" << endl;
        for (auto disease_name : possible_diseases) {
            cout << "- " << disease_name << endl;
        }
    } else {
        cout << "No matching diseases found." << endl;
    }
}

int main() {
    diagnose();
    return 0;
}
