SELECT COUNT(*) AS FISH_COUNT
FROM FISH_INFO F
JOIN FISH_NAME_INFO N
ON F.FISH_TYPE = N.FISH_TYPE
WHERE N.FISH_NAME = 'SNAPPER' OR N.FISH_NAME = 'BASS'
