# D'Jaine Brown
# Assignment 2
# 3/23/2026
# Implement a Student Management System (SMS) that allows users to add, view, and delete student records using a layered architecture approach.
'''
This file only implements the Data Access Layer (Repository Layer) with the functions below:
->Handles data storage and retrieval using a database (SQLite).
  ->create an SQLite database and connect
  ->def create_table(self): Create students table.
  ->def add_student(self, student): add the student to students table.
  ->def get_students(self): fetch all students.
  ->def delete_student(self, student_id): delete the student from students table.
'''

import sqlite3

class StudentRepository:
    def __init__(self, db_name="students.db"):
        self.db_name = db_name
        self.create_table()

    def create_table(self):
        # Connect to the SQLite database
        conn = sqlite3.connect(self.db_name)
        cursor = conn.cursor()

        # Create the students table if it doesn't exist
        cursor.execute('''
            CREATE TABLE IF NOT EXISTS students (
                student_id INTEGER PRIMARY KEY,
                name TEXT NOT NULL,
                age INTEGER NOT NULL,
                grade REAL NOT NULL
            )
        ''')

        # Commit changes and close the connection
        conn.commit()
        conn.close()

    def student_exists(self, student_id):
            # Connect to the SQLite database
            conn = sqlite3.connect(self.db_name)
            cursor = conn.cursor()
            
            # Check if a student with the given ID already exists in the database
            cursor.execute('SELECT COUNT(*) FROM students WHERE student_id = ?', (student_id,))
            count = cursor.fetchone()[0]
            
            # Close the connection
            conn.close()
            
            return count > 0

    def add_student(self, student):
        # Connect to the SQLite database
        conn = sqlite3.connect(self.db_name)
        cursor = conn.cursor()

        # Insert the student record into the students table
        cursor.execute('''INSERT INTO students (student_id, name, age, grade) VALUES (?, ?, ?, ?)''', (student.student_id, student.name, student.age, student.grade))
        
        # Commit changes and close the connection
        conn.commit()
        conn.close()

    def get_students(self):
        # Connect to the SQLite database
        conn = sqlite3.connect(self.db_name)
        cursor = conn.cursor()

        # Fetch all student records from the students table
        cursor.execute('SELECT * FROM students ORDER BY student_id')
        rows = cursor.fetchall()
        
        # Close the connection
        conn.close()
        
        # Convert rows to student objects
        students = []
        for row in rows:
            from student import Student
            student = Student(row[0], row[1], row[2], row[3])
            students.append(student)

        return students

    def delete_student(self, student_id):
        # Connect to the SQLite database
        conn = sqlite3.connect(self.db_name)
        cursor = conn.cursor()

        # Delete a student record from the database
        cursor.execute('DELETE FROM students WHERE student_id = ?', (student_id,))

        # Commit changes and close the connection
        conn.commit()
        conn.close()