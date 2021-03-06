#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Interval
{
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

vector<Interval> merge(vector<Interval>& intervals);
bool LessSort (Interval v1, Interval v2);

int main(){
	vector<Interval> intervals;
	intervals.push_back(Interval(13,17));
	intervals.push_back(Interval(15,18));
	intervals.push_back(Interval(1,11));
	intervals.push_back(Interval(2,9));
	cout << "Input : " << endl;
	for(unsigned int i = 0; i < intervals.size(); i++) 
		cout << "[" <<  intervals[i].start << ", " << intervals[i].end << "]  ";
	vector<Interval> answer = merge(intervals);
	cout << endl << "Output : " << endl;
	for(unsigned int i = 0; i < answer.size(); i++) 
		cout << "[" <<  answer[i].start << ", " << answer[i].end << "]  ";
	cout << endl;
}

vector<Interval> merge(vector<Interval>& intervals) {
	vector<Interval> answer;
	if(intervals.size()<=0) return answer;
	sort(intervals.begin(), intervals.end(), LessSort);
	for(unsigned int i = 0; i < intervals.size(); i++) {
		if(answer.size() == 0) answer.push_back(intervals[i]);
		else if (intervals[i].start > answer.back().end) answer.push_back(intervals[i]);
		else if(intervals[i].end > answer.back().end) answer.back().end = intervals[i].end;
	}
	return answer;
}

bool LessSort(Interval v1, Interval v2) {
	return v1.start < v2.start;
}