//
//  main.cpp
//  PRG-7-11-Exam-Grader
//
//  Created by Keith Smith on 10/8/17.
//  Copyright © 2017 Keith Smith. All rights reserved.
//
//  One of your professors has asked you to write a program to grade her final exams, which
//  consist of only 20 multiple-choice questions. Each question has one of four possible
//  answers: A, B, C, or D. The file CorrectAnswers.txt contains the correct answers for all
//  of the questions, with each answer written on a separate line. The first line contains the
//  answer to the first question, the second line contains the answer to the second question,
//  and so forth (Download the book's source code from the Computer Science Portal at
//  www.pearsonhighered.com/gaddis. You will find the file in the Chapter 07 folder.)
//
//  Write a program that reads the contents of the CorrectAnswers.txt file into a char
//  array, then reads the contents of another file, containing a student's answers, into a
//  second char array. (You can use the file StudentAnswers.txt for testing purposes. This
//  file is also in the Chapter 07 source code folder.) The program should determine the
//  number of questions that the student misesd, then display the following:
//
//  * A list of the questions missed by the student, showing the correct answer and the
//    incorrect answer provided by the student for each missed question
//  * The total number of questions missed
//  * The percentage of questions answered correctly. This can be calculated as
//
//  Correctly Answered Questions / Total Number of Questions
//
//  * If the percentage of correctly answered questions is 70% or greater, the program
//    should indicate that the student passed the exam. Otherwise, it should indicate
//    that the student failed the exam.

#include <iostream>
#include <fstream>

using namespace std;

const int INT_TEST_QUESTIONS = 20;

void populateAnswers(char[]);
void populateStudents(char[]);
void checkAnswers(const char[], const char[], int &);
void calculateScore(const char[], const char[], int);

int main()
{
    char chrArrayAnswers[INT_TEST_QUESTIONS];
    char chrArrayStudent[INT_TEST_QUESTIONS];
    
    int intStudentTestScore;
    
    populateAnswers(chrArrayAnswers);
    populateStudents(chrArrayStudent);
    
    checkAnswers(chrArrayAnswers, chrArrayStudent, intStudentTestScore);
    
    calculateScore(chrArrayAnswers, chrArrayStudent, intStudentTestScore);
    
    return 0;
}

void populateAnswers(char chrArrayAnswers[])
{
    ifstream fileAnswers;
    char chrAnswer;
    
    fileAnswers.open("/Users/bluebackdev/Desktop/CodeBlocks/For Github/07-Arrays and Vectors/PRG-7-11-Exam-Grader/PRG-7-11-Exam-Grader/CorrectAnswers.txt");
    if(!fileAnswers)
    {
        cout << "ERROR OPENING ANSWERS FILE\n";
    }
    
    for(int answers = 0 ; answers < INT_TEST_QUESTIONS ; answers++)
    {
        fileAnswers >> chrAnswer;
        
        chrArrayAnswers[answers] = chrAnswer;
    }
}

void populateStudents(char chrArrayStudent[])
{
    ifstream fileStudents;
    char chrStudent;
    
    fileStudents.open("/Users/bluebackdev/Desktop/CodeBlocks/For Github/07-Arrays and Vectors/PRG-7-11-Exam-Grader/PRG-7-11-Exam-Grader/StudentAnswers.txt");
    if(!fileStudents)
    {
        cout << "ERROR OPENING ANSWERS FILE\n";
    }
    
    for(int student = 0 ; student < INT_TEST_QUESTIONS ; student++)
    {
        fileStudents >> chrStudent;
        
        chrArrayStudent[student] = chrStudent;
    }
}

void checkAnswers(const char chrArrayAnswers[], const char chrArrayStudent[], int &refScore)
{
    int intQuestionNumber;
    int intQuestionsMissed;
    
    intQuestionNumber = 1;
    intQuestionsMissed = 0;
    refScore = 0;
    
    for(int i = 0 ; i < INT_TEST_QUESTIONS ; i++)
    {
        if(chrArrayStudent[i] == chrArrayAnswers[i])
        {
            refScore++;
        }
        else if(chrArrayStudent[i] != chrArrayAnswers[i])
        {
            cout << "Student missed #" << intQuestionNumber << endl;
            cout << "The correct answer was " << chrArrayAnswers[i] << endl;
            cout << "Student guessed " << chrArrayStudent[i] << endl;
            intQuestionsMissed++;
        }
        intQuestionNumber++;
    }
    cout << "The student missed a total of " << intQuestionsMissed << " questions.\n";
}

// Went a little overboard and calculated the exact grade the student recieved.
void calculateScore(const char chrArrayAnswers[], const char chrArrayStudent[], int intStudentScore)
{
    float fltTestPercentage;
    
    fltTestPercentage = static_cast<float>(intStudentScore) / static_cast<float>(INT_TEST_QUESTIONS) * 100.0f;
    
    if(fltTestPercentage >= 90)
    {
        cout << "With a test score of " << fltTestPercentage << "%,\nthe student earned an A.\n";
    }
    else if(fltTestPercentage <= 89 && fltTestPercentage > 80)
    {
        cout << "With a test score of " << fltTestPercentage << "%,\nthe student earned an B.\n";
    }
    else if(fltTestPercentage <= 79 && fltTestPercentage > 70)
    {
        cout << "With a test score of " << fltTestPercentage << "%,\nthe student earned an C.\n";
    }
    else if(fltTestPercentage <= 69 && fltTestPercentage > 60)
    {
        cout << "With a test score of " << fltTestPercentage << "%,\nthe student earned an D.\n";
    }
    else if(fltTestPercentage <= 59)
    {
        cout << "With a test score of " << fltTestPercentage << "%,\nthe student earned an F.\n";
    }
    else
    {
        cout << "There was an error calculating the test score.\n";
    }
}

