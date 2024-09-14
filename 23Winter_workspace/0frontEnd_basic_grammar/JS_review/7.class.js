// class: 객체를 만들어내는 청사진

// class 생성 문법1: 생성자함수
function Student() {
    this.name = '조유찬';
    this.num = 21;
    this.branch = '이과';

    this.avg = (kor, math, eng) => (kor + math + eng) / 3;
}

const student1 = new Student();
console.log(student1);
console.log(student1.avg(100, 100, 90));


// class 생성 문법2: class
class StudnetUsingClass{
    static school = "Seoul Technology and Science"; // 정적데이터 -> instance 생성없이 사용]
     #passwd = 12341234; // 접근제어자 -> 외부에서 참조 불가능
    constructor(name, num, branch) {
        this.name = name;
        this.num = num;
        this.branch = branch;
    }
    avg = (kor, math, eng) => (kor + math + eng) / 3;
    
}

const student2 = new StudnetUsingClass('마틴킴', 15, '문과');
console.log(student2);
console.log(StudnetUsingClass.school);
console.log(student2.passwd);

// get, set: function을 property화
class Name{
    constructor(firstName, lastName) {
        this.firstName = firstName;
        this.lastName = lastName;
    }

    get fullName() {
        return `${this.lastName} ${this.firstName}`;
    }

    set fullName(name) {
        console.log(name);
    }
}

let person = new Name('유찬', '조');
console.log(person);
console.log(person.fullName);
person.fullName = '윤석열';
console.log(person.fullName);

// class별 상속
class Fruit {
    constructor(name, state) {
        this.name = name;
        this.state = state;
    }

    showWhatAreThere = () => console.log("this fruit is " + this.name + " and state is " + this.state);
}

class SellFruit extends Fruit {
    constructor(name, state, price, min, max, allocation) {
        super(name, state);
        this.price = price;
        this.min = min;
        this.max = max;
        this.allocation = allocation;
    }

    sell = () => console.log(this.name + " 하나에 " + this.price + ", 많이많이 사세요~" + " 상태는 " + this.state + "~");

}

let banana = new Fruit('banana', 'good');
console.log(banana);
banana.showWhatAreThere();
let apple = new SellFruit('apple', 'good', 5000, 1, 10, 5);
console.log(apple);
apple.sell();
