// 오브젝트 생성 템플릿
// 1. 생성자 함수(구버전): this와 new가 포인트
function Student(){
    this.num = 13;
    this.name = '김철수';
    this.branch = '이과';;
}
const studentId15 = new Student();
console.log(studentId15);

// 2. class
class Teacher{
    constructor(name, major, school){
        this.name = name;
        this.major = major;
        this.school = school;
    }
}
const teacherId13 = new Teacher('김봉길', '컴퓨터공학과', '노원초등학교');
console.log(teacherId13);

// static method / property
class Car{
    static #maker = 'robean';
    static introYear = 'since 2000~'
    static intro() {
        console.log('welcome to visit our webPage');
        
    }
    constructor(name, horsePower, brand){
        this.name = name;
        this.horsePower = horsePower;
        this.brand = brand;
    }
}

const bmw3series = new Car('320d', '350p', 'bmw');
console.log(Car.intro());
console.log(bmw3series);
console.log(Car.introYear);

// 접근제어자(은닉화): #~
console.log(Car.maker); // undefined

// 상속
class Exam extends Student{
    constructor(math, kor, eng){
        super(13, '윤석열', '이과');
        this.math = math;
        this.kor = kor;
        this.eng = eng;
    }
    avg = () => {return (this.math+this.kor+this.eng)/3;}
}

const exam = new Exam(50, 60, 89);
console.log(exam);
console.log(exam.avg());
console.log(exam.name);








