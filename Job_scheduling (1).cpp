#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure to store job details
struct Job {
    int id;
    int deadline;
    int profit;
};

// Function to sort jobs in descending order of profit
bool compareByProfit(Job a, Job b) {
    return a.profit > b.profit;
}

// Function to schedule jobs and maximize profit
void scheduleJobs(vector<Job>& jobs) {
    // Step 1: Sort jobs by profit (high to low)
    sort(jobs.begin(), jobs.end(), compareByProfit);

    // Step 2: Find maximum deadline
    int maxDeadline = 0;
    for (int i = 0; i < jobs.size(); i++) {
        if (jobs[i].deadline > maxDeadline)
            maxDeadline = jobs[i].deadline;
    }

    // Step 3: Create time slots and initialize to false
    vector<bool> slot(maxDeadline + 1, false); // slot[0] unused
    vector<int> scheduledJobIDs;
    int totalProfit = 0;

    // Step 4: Schedule each job in latest available slot before its deadline
    for (int i = 0; i < jobs.size(); i++) {
        for (int t = jobs[i].deadline; t > 0; t--) {
            if (!slot[t]) {
                slot[t] = true;
                scheduledJobIDs.push_back(jobs[i].id);
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    // Step 5: Output result
    cout << "\nNumber of jobs done: " << scheduledJobIDs.size() << endl;
    cout << "Total profit earned: " << totalProfit << endl;
    cout << "Jobs scheduled (by ID): ";
    for (int i = 0; i < scheduledJobIDs.size(); i++) {
        cout << scheduledJobIDs[i] << " ";
    }
    cout << endl;
}

// Main function
int main() {
    int n;
    cout << "Enter number of jobs: ";
    cin >> n;

    vector<Job> jobs(n);
    cout << "Enter Job ID, Deadline, Profit:\n";
    for (int i = 0; i < n; i++) {
        cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
    }

    // Call function to schedule jobs
    scheduleJobs(jobs);

    return 0;
}
