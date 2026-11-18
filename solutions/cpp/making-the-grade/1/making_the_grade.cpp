#include <array>
#include <string>
#include <vector>

// Round down all provided student scores.
std::vector<int> round_down_scores(std::vector<double> student_scores) {
    std::vector<int> int_scores;
    for (double x : student_scores)
        int_scores.push_back(static_cast<int>(x));
    return int_scores;
}

// Count the number of failing students out of the group provided.
int count_failed_students(std::vector<int> student_scores) {
    int count = 0;
    for(int i = 0; i < student_scores.size(); ++i){
        if(student_scores.at(i) <= 40) count++;
    }
    return count;
}

// Create a list of grade thresholds based on the provided highest grade.
std::array<int, 4> letter_grades(int highest_score) {
    int interval = (highest_score - 40) / 4;
    return {41, 41 + interval, 41 + interval * 2, 41 + interval * 3};
}

// Organize the student's rank, name, and grade information in ascending order.
std::vector<std::string> student_ranking(
    std::vector<int> student_scores, std::vector<std::string> student_names) {
    std::vector<int> indices(student_scores.size());
    std::vector<std::string> rank;
    for (int i = 0; i < indices.size(); ++i)
        indices[i] = i;
    stable_sort(indices.begin(), indices.end(), [&](int a, int b){
        return student_scores[a] > student_scores[b];
    });
    rank.reserve(student_names.size());
    int count = 1;
    for (int i : indices){
        rank.push_back(std::to_string(count++) + ". " + student_names[i] + ": " + std::to_string(student_scores[i]));
    }
    return rank;
}

// Create a string that contains the name of the first student to make a perfect
// score on the exam.
std::string perfect_score(std::vector<int> student_scores,
                          std::vector<std::string> student_names) {
    int index = 0;
    while (index < student_scores.size()){
        if(student_scores.at(index) == 100)
            return student_names.at(index);
        index ++;
    }
    return "";
}
