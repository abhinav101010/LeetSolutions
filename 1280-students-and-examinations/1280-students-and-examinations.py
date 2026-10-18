class Student:
    def __init__(self, studentId, studentName):
        self.studentId = studentId
        self.studentName = studentName

class Subject:
    def __init__(self, subjectName):
        self.subjectName = subjectName

class Examination:
    def __init__(self, studentId, subjectName):
        self.studentId = studentId
        self.subjectName = subjectName

class Solution:
    def studentsAndExaminations(self, students, subjects, examinations):
        examCount = {}
        for e in examinations:
            key = str(e.studentId) + "|" + e.subjectName
            examCount[key] = examCount.get(key, 0) + 1
        res = []
        for s in students:
            for sub in subjects:
                key = str(s.studentId) + "|" + sub.subjectName
                cnt = examCount.get(key, 0)
                res.append([str(s.studentId), s.studentName, sub.subjectName, str(cnt)])
        res.sort(key=lambda r: (int(r[0]), r[2]))
        return res
