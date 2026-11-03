WITH t AS (
    SELECT id, visit_date, people,
           id - ROW_NUMBER() OVER (ORDER BY id) AS grp
    FROM Stadium
    WHERE people >= 100
),
c AS (
    SELECT *, COUNT(*) OVER (PARTITION BY grp) AS cnt
    FROM t
)
SELECT id, visit_date, people
FROM c
WHERE cnt >= 3
ORDER BY visit_date;