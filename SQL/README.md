# SQL
- 관계형 데이터베이스에 정보를 저장하고 처리하기 위한 프로그래밍 언어
- SQL 문을 사용하여 데이터베이스에 정보를 저장, 삭제, 수정, 제거, 조회할 수 있다.

### COUNT 
- 테이블에 존재하는 데이터 갯수를 가져오는 함수
- NULL인 데이터는 제외하고 계산한다.


### MAX
- 하나의 열에서 가장 큰 값을 구하는 함수.
- 숫자뿐만아니라 문자에서도 사용이 가능하다.
``` sql
  SELECT MAX(열이름) AS 별칭
  FROM 테이블이름;
```

### 날짜 추출
- YEAR, MONTH, DAY 함수로 결과를 반환. 이떄 결과는 정수
- 문자열과 하빌 수 없다.
- SELCT 절에는 YEAR(date()) 식으로 사용한다
- WHERE 절에는 YEAR(컬럼명) = 2023과 같은 방식으로 사용



### AVG
- 집계 함수의 종류로서, 숫자 값, 행, 열 또는 셀 그룹의 평균을 반환하는 함수.
- NULL 값이 있으면 오류가 발생할 수 있다.
- NULL 값이 있는 경우 NVL 함수를 이용하여 NULL 값을 0으로 치환해 줘야 오류가 발생하지 않음
- AVG(NVL(price,0))

### ROUND
- ROUND ("값", "자리수")
- 반올림해주는 함수.
- 기본 값은 소수 첫번쨰 자리이다 ROUND(price,0) = ROUND(price)
- 0 -> 1 이면 소수 번째 자리, 2이면 소수 세번째 자리가 된다.

### GROUP BY
- 특정 칼럼을 기준으로 집계함수를 사용하여 집계성 데이터를 추출할 때 사용
- 중복을 제거할 때도 사용이 가능

### JOIN
- 두 테이블의 컬럼을 전부 합쳐서 보여준다.
- 따라서 조건을 넣어 사용해야 한다 (ON or USING) 키워드로 기준을 넣어준다.
- 위 조건을 넣어주지 않으면 카디션 곱이 돼어버려서 이상한 결과가 나온다.

- Join 의 종류
  - JOIN : 두 테이블에서 조건에 맞는 공통된 값만 결과로 보여준다.
  - LEFT JOIN : 왼쪽 테이블의 모든 행을 보여주고 오른쪽에 해당하는 값이 없으면 NULL
  - RIGTH JOIN : 오른쪽 테이블의 모든 행을 보여주고, 왼쪾에 없으면 NULL 

예시
<table>
  <th> FIRST_HALF 테이블 </th>
  <tr>
    <th>FLAVOR</th>
    <th>TOTAL_ORDER</th>
  </tr>
  <tr>
    <td>Vanilla</td>
    <td>3200</td>
  </tr>
  <tr>
    <td>Strawberry</td>
    <td>4500</td>
  </tr>
  <tr>
    <td>ChocoMint</td>
    <td>2500</td>
  </tr>
</table>

<table>
    <th> ICECREAM_INFO 테이블 </th>
  <tr>
    <th>FLAVOR</th>
    <th>INGREDIENT_TYPE</th>
  </tr>
  <tr>
    <td>Vanilla</td>
    <td>sugar_based</td>
  </tr>
  <tr>
    <td>Strawberry</td>
    <td>fruit_based</td>
  </tr>
  <tr>
    <td>Mango</td>
    <td>fruit_based</td>
  </tr>
</table>

LEFT JOIN 결과
<table>
  <tr>
    <th>FLAVOR (FIRST_HALF)</th>
    <th>TOTAL_ORDER</th>
    <th>FLAVOR (ICECREAM_INFO)</th>
    <th>INGREDIENT_TYPE</th>
  </tr>
  <tr>
    <td>Vanilla</td>
    <td>3200</td>
    <td>Vanilla</td>
    <td>sugar_based</td>
  </tr>
  <tr>
    <td>Strawberry</td>
    <td>4500</td>
    <td>Strawberry</td>
    <td>fruit_based</td>
  </tr>
  <tr>
    <td>ChocoMint</td>
    <td>2500</td>
    <td>null</td>
    <td>null</td>
  </tr>
</table>

RIGHT JOIN 결과
<table>
  <tr>
    <th>FLAVOR (FIRST_HALF)</th>
    <th>TOTAL_ORDER</th>
    <th>FLAVOR (ICECREAM_INFO)</th>
    <th>INGREDIENT_TYPE</th>
  </tr>
  <tr>
    <td>Vanilla</td>
    <td>3200</td>
    <td>Vanilla</td>
    <td>sugar_based</td>
  </tr>
  <tr>
    <td>Strawberry</td>
    <td>4500</td>
    <td>Strawberry</td>
    <td>fruit_based</td>
  </tr>
  <tr>
    <td>null</td>
    <td>null</td>
    <td>Mango</td>
    <td>fruit_based</td>
  </tr>
</table>

### CASE
- 조건에 대한 새로운 열을 생성할 때 사용
- 집계함수와 같이 사용한다.

```sql
CASE 컬럼
  WHEN 조건 1 THEN 값 1
  WHEN 조건 2 THEN 값 2
  ELSE 값 3
END
```

### SUBSTRING
- 문자열을 자를 때 사용
- `SUBSTRING("SQL SERVER",5,6)` => 결과 : SERVER
- 시작위치 5부터 길이 6까지 자른다
- `LEFT("SQL SERVER",3)` => 결과 : SQL
- 왼쪽부터 3의 길이를 자른다
- `RIGHT("SQL SERVER",3)` => 결과 : REV
- 오른쪽부터 3의길이를 자른다.
