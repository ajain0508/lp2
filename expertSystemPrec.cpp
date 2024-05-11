#include<bits/stdc++.h>
using namespace std;

vector<string>symptoms = {"Fever", "Cough", "Headache", "Sore throat"};


unordered_map<string,vector<string>>diseases = {
    {"Common cold",{"Fever", "Cough", "Headache", "Sore throat"}},
    {"Flu", {"Fever", "Headache"}},
    {"Strep Throat", {"Fever", "Sore throat"}},
    {"Migraine", {"Headache"}}
};

vector<string> get_user_input(){
    vector<string>user_symptoms;
    char x;
    for(auto symptom : symptoms){
        cout<<"Do you have "<<symptom<< "(y/n) : ";
        cin>>x;
        if(x == 'y'){
            user_symptoms.push_back(symptom);
        }
    }
    return user_symptoms;
}

void diagnose(){
    vector<string>user_symptoms = get_user_input();
    bool f = 0;
    cout<<"\nPossible diseases are : "<<endl;
    for(auto disease : diseases){
        for(auto symptom : disease.second){
            if(find(user_symptoms.begin(),user_symptoms.end(),symptom) != user_symptoms.end()){
                f = 1;
                cout<<" - "<<disease.first<<endl;
                break;
            }
        }
    }
    if(!f) cout<<"None"<<endl;
}

int main(){
    diagnose();
}