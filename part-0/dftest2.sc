spark.read.text("helloworld.txt").selectExpr("sum(size(split(value, '\n')))").as[Long].first
