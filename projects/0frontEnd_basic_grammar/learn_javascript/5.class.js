// class

// class 템플릿1: 생성자 함수
function Student() {
  this.num = 19;
  this.name = '김다연';
  this.branch = '이과';
  this.studentID = 20604;
}

const student1 = new Student();
console.log(student1);

// class 템플릿2: class
class StudentClass {
  constructor(age, name, branch, ID) {
    this.age = age;
    this.name = name;
    this.branch = branch;
    this.ID = ID;
  }
}

const student2 = new StudentClass(23, '조유찬', 'computer engineering', 211);
console.log(student2);

// static level vs method level

class StudentUseStatic {
  static shcool = 'SST-univ';
  constructor(age, name, branch, ID) {
    this.age = age; // method level
    this.name = name;
    this.branch = branch;
    this.ID = ID;
  }
}

const student3 = new StudentUseStatic(
  23,
  '조유찬',
  'computer engineering',
  211
);
console.log(student3.age); // method level에서 호출
console.log(StudentUseStatic.shcool); // class level에서 호출

// 접근제어자: 은닉화

class StudentUseAccessController {
  static #shcool = 'high-school';
  constructor(age, name, branch, ID) {
    this.age = age; // method level
    this.name = name;
    this.branch = branch;
    this.ID = ID;
  }
}

const student4 = new StudentUseAccessController(19, '김다연', '이과', 20604);
console.log(StudentUseAccessController.school); // 접근불가
console.log(student4);

// 함수의 property화: get / set

class NameReturn {
  constructor(firstName, lastName) {
    this.firstName = firstName;
    this.lastName = lastName;
  }
  get fullName() {
    // 접근자 get -> 함수의 내용을 읽고 속성값을 반환한다
    return `${this.lastName} ${this.firstName}`;
  }

  set fullName(name) {
    // 접근자 set -> 함수에 값을 할당가능하게 함
    console.log(name);
  }
}

const student5 = new NameReturn('영희', '김');
// console.log(student.fullName()); 기존에는 함수로 호출해야됨
console.log(student5.fullName); //get을 통해 오류발생 X
NameReturn.fullName = '김철수';

// class 상속
class ExamScore extends StudentUseStatic {
  constructor(eng, math, korean) {
    super(19, '김다연', '이과', 20604);
    this.eng = eng;
    this.math = math;
    this.korean = korean;
  }
  avg = () => (this.eng + this.math + this.korean) / 3;
}
const exam = new ExamScore(50, 30, 60);
console.log(exam);
const examResult = exam.avg();
console.log(examResult);
console.log(StudentUseStatic.shcool);
