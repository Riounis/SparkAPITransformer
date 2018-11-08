val expr = """[\p{Punct}]""".r
spark.read.textFile("helloworld.txt").flatMap(line => expr.replaceAllIn(line, "").split(" ")).map(word => (word, 1)).reduceByKey(_ + _).foreach(println)
