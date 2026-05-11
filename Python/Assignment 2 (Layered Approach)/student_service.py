# D'Jaine Brown
# Assignment 2
# 3/23/2026
# Implement a Student Management System (SMS) that allows users to add, view, and delete student records using a layered architecture approach.
'''
This file only implement the Business Logic Layer (Service Layer) with the functions below:
-> Contains the core logic for managing student records.
   -> def add_student(self, student_id, name, age, grade):
      -> check if age is valid (greater than 15)
      -> check if grade is valid (greater than 70)
      -> If all valid then create a new Student instance and call the repository layer’s add_student function with this instance.
   -> def get_students(self): Fetch all students by calling repository layer’s get_students
   -> def delete_student(self, student_id): Delete the student by calling repository layer’s delete_student
'''

from student import Student
from student_repo import StudentRepository

class StudentService:
    def __init__(self):
        self.repository = StudentRepository()

    # Add a new student with validation checks for age, grade, and unique student ID
    def add_student(self, student_id, name, age, grade):
        # Validate age, grade, and student ID before adding the student
        if age <= 15:
            print("\nError: Student must be older than 15.")
            return False
        elif grade <= 70:
            print("\nError: Student's grade must be greater than 70.")
            return False
        elif self.repository.student_exists(student_id):
            print(f"\nError: Student ID '{student_id}' already exists. Please use a different ID.")
            return False
        else:        
            student = Student(student_id, name, age, grade)
            self.repository.add_student(student)
            print("\nStudent added successfully.")
            return True

    # Display student information
    def get_students(self):
        students = self.repository.get_students()

        if not students:
            print("No students found.")
        else:
            print("\n--- Student List ---")
            for student in students:
                print(student)
        
        return students

    # Delete a student from the repository
    def delete_student(self, student_id):
        # Check if the student exists before attempting to delete
        if self.repository.student_exists(student_id):
            self.repository.delete_student(student_id)
            print(f"\nStudent with ID '{student_id}' deleted successfully.")
            return True
        else:
            print(f"\nError: Student with ID '{student_id}' not found.")
            return False