sc.textFile("helloworld.txt").flatMap(line => """[\p{Punct}]""".r.replaceAllIn(line, "").split(" ")).map(word => (word.capitalize, 1)).sortByKey(true, 0).keys.foreach(println)
