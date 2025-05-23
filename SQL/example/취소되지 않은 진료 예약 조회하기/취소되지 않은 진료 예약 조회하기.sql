SELECT A.APNT_NO,P.PT_NAME,P.PT_NO, A.MCDP_CD, D.DR_NAME, A.APNT_YMD
FROM DOCTOR D
JOIN APPOINTMENT A
ON D.DR_ID = A.MDDR_ID
JOIN PATIENT P
ON A.PT_NO = P.PT_NO
WHERE A.APNT_YMD REGEXP '2022-04-13' AND A.APNT_CNCL_YN  = 'N' AND A.MCDP_CD REGEXP 'CS'
ORDER BY A.APNT_YMD
