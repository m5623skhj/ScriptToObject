# ScriptToObject

## 제작 기간 : 2023.12.01 ~ 2023.12.03

1. 개요
2. 데이터 등록 방법
3. 등록 이외의 사용 방법

---

1. 개요

유저가 정의한 클래스를 지정한 스크립트로 객체화시키고, 메모리로 해당 데이터 들을 들고 있는 클래스를 제공하여, 데이터 관리를 용이하도록 유도한 프로젝트입니다.

---

2. 데이터 등록 방법

2.0. JsonUtil.h의 jsonScriptFolderPath 경로 확인 및 수정

2.1. DataObjectBase 클래스를 상속 받는 사용자 정의 클래스를 정의

2.1.1. SET_DATA_OBJECT(className, keyType, key)를 정의

2.1.2. LoadFromJson()에 들어온 스크립트 데이터를 어떤 변수에 넣을 것인지 정의

2.1.3. PostLoad()정의

2.2. DataRegister.h / DATA_REGISTER()에 ADD_DATA_CLASS_TO_GENERATOR(classType) 선언

2.3. JsonUtil.cpp / LoadAllDataScript(className, fileName)에 선언

---

3. 등록 이외의 사용 방법

3.1. LoadAllDataScript()를 가장 먼저 호출하여, 모든 스크립트를 미리 로드

3.2.1. 정상적으로 로딩이 완료되었다면, FIND_DATA(className, key)로 원하는 데이터를 얻어옴

3.2.2. 해당하는 키가 없을 경우, nullptr이 반환되므로, 반드시 반환 결과값이 nullptr인지 확인 필요