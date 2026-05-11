# D'Jaine Brown
# Assignment 2
# 3/23/2026
# Implement a Student Management System (SMS) that allows users to add, view, and delete student records using a layered architecture approach.
# This file only implements the model with the Student class.

# Create a Student class with attributes (student_id, name, age, grade)
class Student:
    def __init__(self, student_id, name, age, grade):
        self.student_id = student_id
        self.name = name
        self.age = age
        self.grade = grade

    def __str__(self):
        return f"Student ID: {self.student_id}, Name: {self.name}, Age: {self.age}, Grade: {self.grade}"