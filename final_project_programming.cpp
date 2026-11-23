
#include <iostream>
#include <string>
using namespace std;

const int SIZE = 10;       
const int PASS_MARK = 50;  

// تعريف functions
void show_menu();                                              
int read_number(int low, int high);                            
void enter_marks(int student_marks[], int size);               
void display_marks(string student_names[], int student_marks[], int size);
int calculate_sum(int student_marks[], int size);
double calculate_average(int sum, int size);
int find_highest_index(int student_marks[], int size);
int find_lowest_index(int student_marks[], int size);
int count_passed(int student_marks[], int size);
char get_grade(int mark);
void grade_of_student(string student_names[], int student_marks[], int size);
void search_student(string student_names[], int student_marks[], int size);
int count_above_average(int student_marks[], int size, double average);
void edit_mark(string student_names[], int student_marks[], int size);  // extra feature 2

int main() {
    // default names and marks for 10 students using arrays
    string student_names[SIZE] = {"Ahmed", "Mona", "Youssef", "Sara", "Omar",
                                  "Nour", "Khaled", "Laila", "Hassan", "Mariam"};
    int student_marks[SIZE] = {85, 42, 67, 91, 50, 73, 38, 58, 79, 100};
        //اللي بينفذ function حسب اختيار المستخدم و سيستمر في اعادة عرض menu حتى يختار المستخدم 0 للخروج
    int choice;
    do {
        show_menu();
        choice = read_number(0, 10);

        switch (choice) {
            case 1:
                enter_marks(student_marks, SIZE);
                break;
            case 2:
                display_marks(student_names, student_marks, SIZE);
                break;
            case 3: {
                int sum = calculate_sum(student_marks, SIZE);
                cout << "Total   : " << sum << endl;
                cout << "Average : " << calculate_average(sum, SIZE) << endl;
                break;
            }
            case 4: {
                int index = find_highest_index(student_marks, SIZE);
                cout << "Highest mark: " << student_marks[index]
                     << " (student " << index + 1 << ")" << endl;
                break;
            }
            case 5: {
                int index = find_lowest_index(student_marks, SIZE);
                cout << "Lowest mark: " << student_marks[index]
                     << " (student " << index + 1 << ")" << endl;
                break;
            }
            case 6: {
                int passed = count_passed(student_marks, SIZE);
                cout << "Passed: " << passed << endl;
                cout << "Failed: " << SIZE - passed << endl;
                break;
            }
            case 7:
                grade_of_student(student_names, student_marks, SIZE);
                break;
            case 8:
                search_student(student_names, student_marks, SIZE);
                break;
            case 9: {
                double average = calculate_average(calculate_sum(student_marks, SIZE), SIZE);
                cout << "Students above the average: "
                     << count_above_average(student_marks, SIZE, average) << endl;
                break;
            }
            case 10:
                edit_mark(student_names, student_marks, SIZE);
                break;
            case 0:
                cout << "Goodbye!" << endl;
                break;
        }
    } while (choice != 0);

    return 0;
}

// عرض menu 

void show_menu() {
    cout << "\n===== Student Marks Manager =====" << endl;
    cout << "1) Enter marks" << endl;
    cout << "2) Display all marks" << endl;
    cout << "3) Total and average" << endl;
    cout << "4) Highest mark" << endl;
    cout << "5) Lowest mark" << endl;
    cout << "6) Passed and failed" << endl;
    cout << "7) Mark to grade letter" << endl;
    cout << "8) Search for a student" << endl;
    cout << "9) Students above the average" << endl;
    cout << "10) Edit a student's mark" << endl;
    cout << "0) Exit" << endl;
    cout << "Your choice: ";
}

// يتاكد من ان المستخدم ادخل رقم بين low و high
int read_number(int low, int high) {
    int number;
    do {
        cin >> number;
        if (number < low || number > high)
            cout << "Wrong input! Enter a number from " << low << " to " << high << ": ";
    } while (number < low || number > high);
    return number;
}
// user يقدر يدخل marks لكل الطلاب و يتاكد من ان كل mark بين 0 و 100
// و يخزن marks في array الاصلي student_marks
void enter_marks(int student_marks[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "Mark of student " << i + 1 << " (0-100): ";
        student_marks[i] = read_number(0, 100);
    }
}
// يعرض marks لكل الطلاب مع اسمائهم
// عن طريق looping علي كل mark في array student_marks و كل اسم في array student_names
void display_marks(string student_names[], int student_marks[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "Student " << i + 1 << " (" << student_names[i] << "): "
             << student_marks[i] << endl;
    }
}
// بيحسب مجموع marks لكل الطلاب و يرجع المجموع
// عن طريق looping علي كل mark في array student_marks
int calculate_sum(int student_marks[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum = sum + student_marks[i];
    }
    return sum;
}
// بيحسب المتوسط عن طريق قسمة المجموع علي عدد الطلاب و يرجع المتوسط
// using castting to double to avoid integer division
double calculate_average(int sum, int size) {
    return (double)sum / size;
}
// بيرجع INDEX اعلي mark في array student_marks
// عن طريق looping علي كل mark في array student_marks و مقارنة كل mark بالاعلي mark لحد دلوقتي
int find_highest_index(int student_marks[], int size) {
    int highest_index = 0;
    for (int i = 1; i < size; i++) {
        if (student_marks[i] > student_marks[highest_index])
            highest_index = i;
    }
    return highest_index;
}

// بيرجع INDEX اقل mark في array student_marks
// عن طريق looping علي كل mark في array student_marks و مقارنة كل mark بالاقل mark لحد دلوقتي
int find_lowest_index(int student_marks[], int size) {
    int lowest_index = 0;
    for (int i = 1; i < size; i++) {
        if (student_marks[i] < student_marks[lowest_index])
            lowest_index = i;
    }
    return lowest_index;
}
// بيحسب عدد الطلاب اللي نجحوا و يرجع العدد
// عن طريق looping علي كل mark في array student_marks و مقارنة كل mark بال PASS_MARK
int count_passed(int student_marks[], int size) {
    int passed = 0;
    for (int i = 0; i < size; i++) {
        if (student_marks[i] >= PASS_MARK)
            passed++;
    }
    return passed;
}

// Converts one mark to a grade letter
char get_grade(int mark) {
    if (mark >= 85)
        return 'A';
    else if (mark >= 75)
        return 'B';
    else if (mark >= 65)
        return 'C';
    else if (mark >= PASS_MARK)
        return 'D';
    else
        return 'F';
}
// asks for a student number, then prints that student's mark and grade letter
// عن طريق طلب رقم الطالب من المستخدم و التأكد انه بين 1 و size و بعدين طباعة mark و grade letter للطالب
void grade_of_student(string student_names[], int student_marks[], int size) {
    cout << "Student number (1-" << size << "): ";
    int number = read_number(1, size);
    int mark = student_marks[number - 1];  // number 1 is stored at index 0
    cout << student_names[number - 1] << ": " << mark
         << " -> grade " << get_grade(mark) << endl;
}
// asks for a student number, then prints that student's mark and if he passed or failed
// عن طريق طلب رقم الطالب من المستخدم و التأكد انه بين 1 و size و بعدين طباعة mark و if he passed or failed للطالب
void search_student(string student_names[], int student_marks[], int size) {
    cout << "Student number (1-" << size << "): ";
    int number = read_number(1, size);
    int mark = student_marks[number - 1];
    cout << student_names[number - 1] << " got " << mark << endl;

    // using nested if statements to check if the student passed or failed and if he passed with excellence
    if (mark >= PASS_MARK) {
        if (mark >= 85)
            cout << "Passed with excellence" << endl;
        else
            cout << "Passed" << endl;
    } else {
        cout << "Failed" << endl;
    }
}
// بيحسب عدد الطلاب اللي جابوا mark اعلي من المتوسط و يرجع العدد
// عن طريق looping علي كل mark في array student_marks و مقارنة كل mark بالمتوسط
int count_above_average(int student_marks[], int size, double average) {
    int count = 0;
    int i = 0;
    while (i < size) {  // while loop
        if (student_marks[i] > average)
            count++;
        i++;
    }
    return count;
}
// بيسمح للمستخدم ان يعدل mark لطالب معين و يخزن mark الجديد في array الاصلي student_marks
// عن طريق طلب رقم الطالب من المستخدم و التأكد انه بين 1 و size و بعدين طلب mark الجديد و التأكد انه بين 0 و 100
void edit_mark(string student_names[], int student_marks[], int size) {
    cout << "Student number (1-" << size << "): ";
    int number = read_number(1, size);
    cout << "New mark for " << student_names[number - 1] << " (0-100): ";
    student_marks[number - 1] = read_number(0, 100);
}
