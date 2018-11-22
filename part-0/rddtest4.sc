val expr = """[\p{Punct}]""".r
sc.textFile("helloworld.txt").flatMap(line => expr.replaceAllIn(line, "").split(" ")).map(word => (word, 1)).reduceByKey(_ + _).foreach(println)
