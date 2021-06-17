#include <gtest/gtest.h>
#include "Student.h"

TEST(Student, Average){
    vector<int> x {2,4,6,8,10};
    Student student("Vardas1", "Pavardė1", x);
    student.setExamGrade(10);
    student.finalGradeAverage();
    EXPECT_EQ(student.getFinalGrade(), 8.4);
}

TEST(Student, Median){
    vector<int> x {2,4,6,8,10};
    Student student("Vardas1", "Pavardė1", x);
    student.setExamGrade(10);
    student.finalGradeMedian();
    EXPECT_EQ(student.getFinalGrade(), 8.4);
}

TEST(Student, Assign){
    vector<int> x {2,4,6,8,10};
    Student student("Vardas1", "Pavardė1", x);
    student.setExamGrade(10);
    student.finalGradeMedian();
    Student studentCopy = student;
    EXPECT_EQ(student.getFirstName(), studentCopy.getFirstName());
    EXPECT_EQ(student.getLastName(), studentCopy.getLastName());
    EXPECT_EQ(student.getHomeworkSize(), studentCopy.getHomeworkSize());
    EXPECT_EQ(student.getFinalGrade(), studentCopy.getFinalGrade());
    EXPECT_EQ(student.getGrades(), studentCopy.getGrades());
}

TEST(Student, Copy){
    vector<int> x {2,4,6,8,10};
    Student student("Vardas1", "Pavardė1", x);
    student.setExamGrade(10);
    student.finalGradeMedian();
    Student studentCopy(student);
    EXPECT_EQ(student.getFirstName(), studentCopy.getFirstName());
    EXPECT_EQ(student.getLastName(), studentCopy.getLastName());
    EXPECT_EQ(student.getHomeworkSize(), studentCopy.getHomeworkSize());
    EXPECT_EQ(student.getFinalGrade(), studentCopy.getFinalGrade());
    EXPECT_EQ(student.getGrades(), studentCopy.getGrades());
}
