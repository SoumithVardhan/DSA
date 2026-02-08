#include <iostream>
#include <vector>
using namespace std;

// Class to represent a single meeting
class Meeting {
public:
    int startTime;  // Start time of the meeting
    int endTime;    // End time of the meeting
    int position;   // Original index/position of the meeting in the input
};

class Solution {
public:
    int maxMeetings(vector<int>& start, vector<int>& end) {
        int n = start.size();  // Number of meetings

        // Array of Meeting objects
        Meeting meetings[n];

        // Populate the Meeting objects with start time, end time, and original position
        for (int i = 0; i < n; i++) {
            meetings[i].startTime = start[i];
            meetings[i].endTime = end[i];
            meetings[i].position = i + 1;   // 1-based indexing
        }

        // Sort the meetings based on their end times (earliest ending meeting first)
        // This is the greedy step to maximize the number of meetings
        sort(meetings, meetings + n, [](auto& a, auto& b) {
            return a.endTime < b.endTime;
        });

        // Create a vector to store the positions of selected meetings (1-based indexing)
        vector<int> selectedMeetings;

        // Always select the first meeting by default, 
        // because after sorting by end time it ends earliest
        // and thus maximizes chances to attend more meetings
        selectedMeetings.push_back(meetings[0].position);

        // Keep track of the end time of the last selected meeting
        int lastEnd = meetings[0].endTime;

        // Iterate through the rest of the meetings
        for (int i = 1; i < n; i++) {
            // If the current meeting starts after the last selected meeting ends,
            // we can attend this meeting as well
            if (meetings[i].startTime > lastEnd) {
                selectedMeetings.push_back(meetings[i].position);  // Select this meeting
                lastEnd = meetings[i].endTime;  // Update the end time
            }
        }

        // Return the total number of meetings that can be attended
        return selectedMeetings.size();
    }

    //Note : If you want to return the positions of the meetings
    //Then you can return the selectedMeetings vector instead of its size
};