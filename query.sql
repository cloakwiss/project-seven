WITH ttypes as (select datatype from FunctionParameters group by FunctionParameters.datatype),
	splits as (SELECT datatype, CASE
		WHEN like('PSS%', datatype) THEN datatype
		WHEN like('PTP%', datatype) THEN datatype
		WHEN like('LP%', datatype) THEN substr(datatype, 3)
		WHEN like('P%', datatype) THEN substr(datatype, 2)
		WHEN like('const %', datatype) THEN substr(datatype, 7)
		ELSE datatype
		END AS n 
	FROM ttypes)
select * from Symbol JOIN splits ON splits.n = Symbol.name WHERE Symbol.type IS 'structure';