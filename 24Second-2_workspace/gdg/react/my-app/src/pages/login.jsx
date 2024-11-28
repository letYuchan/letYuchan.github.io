// src/pages/Login.jsx
import React, { useState } from 'react';
import { useNavigate } from 'react-router-dom'; // useNavigate import
import LoginForm from '../components/LoginForm';

function Login() {
  const [password, setPassword] = useState('');
  const [errorMessage, setErrorMessage] = useState('');
  const navigate = useNavigate(); // useNavigate 훅 사용

  // 미리 정해진 비밀번호
  const correctPassword = "password123";

  const handleSubmit = (event) => {
    event.preventDefault();

    if (password !== correctPassword) {
      setErrorMessage("비밀번호가 일치하지 않습니다.");
    } else {
      setErrorMessage("");
      alert("로그인 성공!");
      navigate("/onboarding"); // /onboarding 페이지로 이동
    }
  };

  return (
    <Login>
    </Login>
  );
}

export default Login;
