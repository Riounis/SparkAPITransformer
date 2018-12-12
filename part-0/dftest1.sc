spark.range(1, 100).selectExpr("id as _1").filter("_1%3 == 0").collect()
