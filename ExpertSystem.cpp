#include <iostream>
#include <vector>
using namespace std;

// Function to ask user a Yes/No question and return true for 'Y'/'y'
bool askQuestion(const string &question) {
    char response;
    cout << question << " (Y/N): ";
    cin >> response;
    return (response == 'Y' || response == 'y');
}

// Function to explain the diagnosis based on matched condition
void explainDiagnosis(const string &diagnosis) {
    if (diagnosis == "allergies") {
        cout << "You may have Allergy because of symptoms like red watery eyes, itching, swelling, throat itching, etc." << endl;
    } else if (diagnosis == "flu") {
        cout << "You may have COVID-19 flu because of symptoms like loss of smell and taste, fever, shortness of breath, etc." << endl;
    } else if (diagnosis == "fever") {
        cout << "You may have Fever because of symptoms like body ache, high body temperature, headache, chills, etc." << endl;
    } else if (diagnosis == "cold") {
        cout << "You may have Cold because of symptoms like runny and stuffy nose, sneezing, cough, etc." << endl;
    } else if (diagnosis == "appendicitis") {
        cout << "You may have Appendicitis because of symptoms like pain in the lower right abdominal region, loss of appetite, etc." << endl;
    } else if (diagnosis == "foodpoisioning") {
        cout << "You may have Food Poisoning because of symptoms like stomach ache, diarrhea, vomiting, etc." << endl;
    } else if (diagnosis == "strepthroat") {
        cout << "You may have Strep Throat because of symptoms like tonsils, neck and throat pain, sore throat, etc." << endl;
    } else if (diagnosis == "Diabetes") {
        cout << "You may have Diabetes because of symptoms like frequent urination, weight loss, tiredness and weakness, etc." << endl;
    } else {
        cout << "No Relevant Diagnosis found." << endl;
    }
}

// Each function below checks for a set of symptoms and returns true if any is found

bool diagnoseAllergies() {
    bool symptom1 = askQuestion("Do you experience red watery eyes?");
    bool symptom2 = askQuestion("Do you experience itching or swelling in the body?");
    bool symptom3 = askQuestion("Do you have redness in the body?");
    bool symptom4 = askQuestion("Are you experiencing itching in the throat?");
    return symptom1 || symptom2 || symptom3 || symptom4;
}

bool diagnoseFever() {
    bool symptom1 = askQuestion("Do you experience body chills?");
    bool symptom2 = askQuestion("Do you have temperature higher than 37.5°C?");
    bool symptom3 = askQuestion("Do you have headache?");
    bool symptom4 = askQuestion("Do you have body ache?");
    return symptom1 || symptom2 || symptom3 || symptom4;
}

bool diagnoseFlu() {
    bool symptom1 = askQuestion("Do you have loss of sense of smell and taste?");
    bool symptom2 = askQuestion("Do you have sore throat?");
    bool symptom3 = askQuestion("Do you have cough, body and muscle ache?");
    bool symptom4 = askQuestion("Do you experience shortness of breath?");
    return symptom1 || symptom2 || symptom3 || symptom4;
}

bool diagnoseCold() {
    bool symptom1 = askQuestion("Do you have runny or stuffy nose?");
    bool symptom2 = askQuestion("Do you have headache?");
    bool symptom3 = askQuestion("Are you sneezing frequently?");
    return symptom1 || symptom2 || symptom3;
}

bool diagnoseAppendicitis() {
    bool symptom1 = askQuestion("Do you experience pain in the lower right part of your abdomen?");
    bool symptom2 = askQuestion("Are you feeling nauseous?");
    bool symptom3 = askQuestion("Are you experiencing loss of appetite?");
    return symptom1 || symptom2 || symptom3;
}

bool diagnoseStrepThroat() {
    bool symptom1 = askQuestion("Do you have tonsils?");
    bool symptom2 = askQuestion("Do you experience pain in the throat, neck, and head?");
    bool symptom3 = askQuestion("Do you have sore throat?");
    return symptom1 || symptom2 || symptom3;
}

bool diagnoseFoodPoisoning() {
    bool symptom1 = askQuestion("Do you experience stomach ache?");
    bool symptom2 = askQuestion("Are you feeling nauseous?");
    bool symptom3 = askQuestion("Are you vomiting frequently?");
    bool symptom4 = askQuestion("Do you have symptoms of diarrhea?");
    return symptom1 || symptom2 || symptom3 || symptom4;
}

bool diagnoseDiabetes() {
    bool symptom1 = askQuestion("Are you feeling thirsty frequently?");
    bool symptom2 = askQuestion("Do you experience frequent urination?");
    bool symptom3 = askQuestion("Did you have unexpected weight loss?");
    bool symptom4 = askQuestion("Are you feeling tired and weak?");
    return symptom1 || symptom2 || symptom3 || symptom4;
}

int main() {
    vector<string> diagnoses;

    bool hasAllergies       = diagnoseAllergies();
    bool hasAppendicitis    = diagnoseAppendicitis();
    bool hasFlu             = diagnoseFlu();
    bool hasCold            = diagnoseCold();
    bool hasFever           = diagnoseFever();
    bool hasStrepThroat     = diagnoseStrepThroat();
    bool hasFoodPoisoning   = diagnoseFoodPoisoning();
    bool hasDiabetes        = diagnoseDiabetes();

    if (hasAllergies)       diagnoses.push_back("allergies");
    if (hasAppendicitis)    diagnoses.push_back("appendicitis");
    if (hasFlu)             diagnoses.push_back("flu");
    if (hasCold)            diagnoses.push_back("cold");
    if (hasFever)           diagnoses.push_back("fever");
    if (hasStrepThroat)     diagnoses.push_back("strepthroat");
    if (hasFoodPoisoning)   diagnoses.push_back("foodpoisioning");
    if (hasDiabetes)        diagnoses.push_back("Diabetes");

    cout << "\n====================" << endl;
    cout << "     START OF REPORT" << endl;
    cout << "====================\n" << endl;

    if (!diagnoses.empty()) {
        cout << "Based on your symptoms, the system suggests:\n" << endl;
        for (const auto &diagnosis : diagnoses) {
            cout << "● ";
            explainDiagnosis(diagnosis);
        }
    } else {
        cout << "No diagnosis found for the symptoms." << endl;
    }

    cout << "\n==================" << endl;
    cout << "     END OF REPORT" << endl;
    cout << "==================\n" << endl;

    return 0;
}

