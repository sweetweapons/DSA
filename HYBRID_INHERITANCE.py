class University(object):
    def __init__(self, uname):
        self.uname = uname
        print(f"the name of the university is {self.uname}")

class Course(University):
    def __init__(self, cname, uname):
        self.cname = cname
        super().__init__(uname)
        print(f"(classcourse) the course is {self.cname}, university name is {self.uname}")
        # return super().show_detail(u_name)

class Branch(University):
    def __init__(self, bname , uname):
        self.bname = bname
        super().__init__(uname)
        print(f"(classbranch)  branch is {self.bname} and university is{self.uname}")
        # return super().show_detail(u_name)

class Student(Course, Branch):
    def __init__(self, sname, cname, bname, uname):
        super().__init__(cname, uname)  # Call Course constructor
        super().__init__(bname, uname)  # Call Branch constructor
        self.sname = sname        
        print(f"Student of branch: \n\tstudent: {self.sname} \n\tbranch: {self.bname} \n \t University: {self.uname} \nstudent of class course: \n\t student: {self.student_name} \n\t course: {self.course} \n\t University: {self.university}")
        # return super().show_detail(u_name, c_name)

class Faculty(Branch):
    def __init__(self, uname,bname,fname) -> None:
        super().__init__(bname, uname)  # Call Branch constructor
        self.fname = fname
        print(f"(facultyclass) faculty: {self.fname}, branch: {self.bname} , university: {self.uname}")
        # super().__init__(u_name, b_name)

f1 = Faculty("PESU","MCA","VEENA")
s1= Student("MCA", "CS","bca","avc")
            


