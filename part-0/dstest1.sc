spark.range(1, 100).as[Long].filter((x:Long) => x%3 == 0).collect()
