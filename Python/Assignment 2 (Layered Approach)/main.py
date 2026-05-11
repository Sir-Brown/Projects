# D'Jaine Brown
# Assignment 2
# 3/23/2026
# Implement a Student Management System (SMS) that allows users to add, view, and delete student records using a layered architecture approach.
'''
Provides a command line interface (CLI) for users to interact with the application.
-> Implement an infinite loop that has an Exit choice.
'''

from student_service import StudentService

# Display menu options to the user
def display_menu():
    print("\n" + "="*57)
    print("\t\tSTUDENT MANAGEMENT SYSTEM")
    print("="*57)
    print("1. Add Student")
    print("2. View Students")
    print("3. Delete Student")
    print("4. Exit")
    print("="*57)

# Interface functions for each menu option

# Handles: Adding a new student
def add_students(service):
    print("\n--- Add New Student ---")
    
    # Validate user input for student details
    try:
        # Get student details from user input
        student_id = int(input("Enter Student ID: "))
        name = input("Enter Student Name: ")
        age = int(input("Enter Student Age: "))
        grade = float(input("Enter Student Grade: "))
        
        service.add_student(student_id, name, age, grade)
        
    except ValueError:
        print("Error: Invalid input. Please enter numbers for ID, age, and grade.")

# Handles: Viewing all students
def view_students(service):
    service.get_students()

# Handles: Deleting a student record
def delete_students(service):
    print("\n--- Delete Student ---")
    
    try:
        student_id = int(input("Enter the Student ID for the student whose record you want to delete: "))
        service.delete_student(student_id)       
    except ValueError:
        print("\nError: Invalid input. Please enter a number for student ID.")

def main():
    # Call the StudentService constructor
    service = StudentService()
    
    # Begin the loop to display the menu and handle user choices
    while True:
        display_menu()
        
        try:
            choice = int(input("\nEnter your choice (1-4): "))
            
            if choice == 1:
                add_students(service)            
            elif choice == 2:
                view_students(service)            
            elif choice == 3:
                delete_students(service)             
            elif choice == 4:
                print("\nThank you for using the Student Management System. Goodbye!")
                break             
            else:
                print("\nError: Invalid choice. Please enter a number between 1 and 4.")

        except ValueError:
            print("\nError: Invalid input. Please enter a number.")

if __name__ == "__main__":
    main()