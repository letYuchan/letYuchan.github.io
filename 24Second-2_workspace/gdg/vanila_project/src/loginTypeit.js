'use srtrict';
new TypeIt(".divider", {
    speed: 50,
    loop: true
  })
    .type("ASK")
    .pause(500) // 500ms 대기
    .delete(3) // 5글자 삭제
    .type("ASK ANYTHING")
    .go();