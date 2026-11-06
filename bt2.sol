// SPDX-License-Identifier: MIT
pragma solidity ^0.8.18;

contract StudentData {
    
    // 1. Define the Structure
    struct Student {
        string name;
        uint age;
        string course;
    }

    // 2. Declare an Array to hold multiple Students
    Student[] public students;

    // 3. Function to add a student (This will cost Gas!)
    function addStudent(string memory _name, uint _age, string memory _course) public {
        // Create a new student in memory and push it to the array
        students.push(Student(_name, _age, _course));
    }

    // 4. Function to get a specific student's data
    function getStudent(uint _index) public view returns (string memory, uint, string memory) {
        Student memory s = students[_index];
        return (s.name, s.age, s.course);
    }
}
