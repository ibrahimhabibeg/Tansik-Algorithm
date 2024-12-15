# Gale-Shapley Inspired Stable Matching Algorithm to Match High-School Students to Academic Programs

## Overview

This project implements a [Gale-Shapley-inspired](https://www.nobelprize.org/uploads/2018/06/popular-economicsciences2012.pdf) stable matching algorithm to match students to their preferred academic programs. The algorithm's functionality is similar to the famous *tansik* system used in Egypt to match high-school graduates to faculties. However, the algorithm adds the ability for each academic program to define its custom criteria for accepting students allowing programs to give more weight to the grades of specific subjects, students' interests, or students' extracurriculars.

One example showcasing the power of this feature is for medicine programs to give more weight to the students' biology and chemistry scores and for engineering programs to give more weight to the student's math and physics scores. Moreover, the added flexibility empowers universities to evaluate the student as a whole human being, rather than just a grade.

## What does it add to the Egyptian tansik system?

Egypt indeed has a student matching system called tansik. This program allows students to order the academic programs according to their preferences and the system will match students to the most appropriate program.

The problem with such a system is that it blindly evaluates all students only according to their average high school grade, introducing multiple issues.

The first issue is that all academic programs evaluate students in the same manner. This is counterintuitive since an arts program doesn't care for the student's Physics grade, an Engineering program doesn't care for the student's Biology grade, and a Medicine program doesn't care for the student's Arabic grade.

Unfortunately, the current system forces all programs to treat all the students in the same way and the weights for the student's grades are unified across all programs damaging the program and discriminating the students.

Another issue with the current system is its treatment of students as only a grade. The current system is unable to utilize any other data about the student since it can only comprehend the student's high school grade. This act dehumanizes the student. A student is much more than a number on paper. A bad exam day shouldn't end his or her career. A student should be evaluated for who he is, for his goals, for his principles, for his passion, and for his experiences.

We should evaluate students for the whole 18 years they have been on Earth not only an exam day. I oppose any system that demeans a human by solely evaluating him as a number whether it's high school grade, GPA, SAT, or IQ.

## The Algorithm

The algorithm implemented here is inspired by the **Nobel Prize winning** Gale-Shapley Algorithm. This algorithm has multiple applications. This repo uses the algorithm to match high school students to academic programs.

The program here adds two important features to the classical algorithm:

- Each program has a certain number of students it can accept
- A comparator is used to sort students and programs instead of relying on a premade list

If the comparator doesn't define a [linear order](https://ece.uwaterloo.ca/~dwharder/aads/Abstract_data_types/Linear_ordering/) on the students or programs, then the results of the program won't be deterministic. Being transitive and strongly connected won't be an issue with a typical comparator; however, problems may arise in maintaining the antisymmetry constraint, a student may like two programs equally and a program may like two students equally.

We can easily avoid this issue by adding a unique identifier for each object in the system and using the identifier value to select a student or program in case of stalemates.

The algorithm implemented here provides us with two important guarantees:

1. **[Stability](https://homes.cs.washington.edu/~anuprao/pubs/CSE421Wi2020/01stable-matching.pdf)**: No student will prefer a program over the one he is matched with if the program prefers the student over any other student it is matched with.
2. **Optimality**: The algorithm will always find the best possible program for each student.

## How to use the program

The program is written in C++ and can be run from the `main.cpp` file. The heart of the program is the `StudentMatchingSystem` class. This class is responsible for matching students to programs. The current program uses a list of predefined programs and 100 randomly generated students. The program then matches the students to the programs and prints the results. You can easily modify the program to use your list of programs and students. Moreover, you can extend the `Student` and `Program` classes to add more data about the students and programs.

The `StudentMatchingSystem` only requires a list of students and programs to work. It only assumes the following from the `Student` and `Program` classes:

- Both classes have `getComparator` method that returns a comparator to sort the students and programs respectively.
- `Student` class has `setProgram` method that sets the program the student is matched with at the end of the algorithm.
- `Program` class has `addStudent` method that adds a student to the program at the end of the algorithm.
- `Program` class has `getCapacity` method that returns the number of students the program can accept.
