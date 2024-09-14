function Person(name){
    this.name = name;
}

Person.prototype.callName = function(){
    return this.name;
}

const person = new Person('조유찬');
console.log(person.__proto__.callName()); // undefined -> prototype 객체의 callName의 this는 prototype 객체에 바인딩됨
console.log(person.callName()); // 조유찬 -> 정상출력할 수 있는 이유는 callName() 속 this가 Person을 직접 가리키기 때문
 // 결론적으로 this는 가장 인접한 객체에 바인딩됨

 // 어떤 부모의 메소드나 프로퍼티가 각 자식 객체에 각각 복사되면 메모리가 낭비될 것
 // prototype에 선언해준다면 각 객체는 추가적인 메모리 할당 없이 참조를 통해 해당
 // 메소드나 프로퍼티를 사용가능


 // prototype에 추가
 function ExampleFunction(){ // 생성자함수 생성

 }
 ExampleFunction.prototype.someMethod = function(){
    console.log("This is a" + this.someMethod);
    
 }

 const exampleObject = new ExampleFunction();
 exampleObject.someMethod(); // this는 exampleObject에 바인딩

// 생성자함수에 직접 추가
//  function ExampleFunction(){
//     this.someMethod = function(){
//     console.log('This is a' + this.someMethod.);
//  }