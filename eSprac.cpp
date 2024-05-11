#include<bits/stdc++.h>
using namespace std;

vector<string>symptoms = {"Fever","Cough","Headache","Sore throat"};

unordered_map<string,vector<string>> diseases = {
    {"Common Cold",{"Fever","Cough","Headache","Sore throat"}},
    {"Flu",{"Fever","Cough","Headache"}},
    {"Strep Throat",{"Sore throat","Cough"}},
    {"Migraine",{"Headache"}}
};

vector<string> get_user_input(){
    vector<string>user_symptoms;
    for(auto i : symptoms){
        char a;
        cout<<"Do you have "<<i<<" (y/n) : ";
        cin>>a;
        if(tolower(a) == 'y'){
            user_symptoms.push_back(i);
        }
    }
    return user_symptoms;
}

void diagnose(){
    vector<string>user_symptoms = get_user_input();
    vector<string>PossibleDiseases;
    for(auto i: diseases){
        for (auto symptom : i.second){
            if(find(user_symptoms.begin(),user_symptoms.end(),symptom) != user_symptoms.end()){
                PossibleDiseases.push_back(i.first);
                break;
            }
        }
    }
    
    if(PossibleDiseases.size() == 0) cout<<"No diseases found"<<endl;
    for(auto i : PossibleDiseases){
        cout<< " - "<<i<<endl;
    }
}

int main(){
    diagnose();
}