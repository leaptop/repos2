package trig_interpolation.interpolation;

public class Trig {
	private Points[] points;
	private int degree;

	private Points[] readPointsFromFile(String filePath) {
		Points[] points = null;

		if(filePath != null && !filePath.isEmpty()) {
			try {
				File file = new File(filePath);
				Scanner scanner = new Scanner(file);

				if(scanner.hasNextLine()) {
					String[] firstLine = scanner.nextLine().trim().split("\\s+");
					if(firstLine.length == 1) {
						int pointsNumber = 0;

						try {
							pointsNumber = Integer.parseInt(firstLine[0]);
						} catch(NumberFormatException e) {
							System.out.println("Wrong points number format.");
						}
					} else {
						return null;
					}

					points = new Points[pointsNumber];
					double x = 0.0;
					double y = 0.0;

					for(int i = 0; i < pointsNumber; i++) {
						if(scanner.hasNextLine()) {
							String[] line = scanner.nextLine().trim().split("\\s+");
						
							if(item.length == 2) {
								try {
									x = Double.parseDouble(item[0])
									y = Double.parseDouble(item[1])
								} catch(NumberFormatException e) {
									System.out.println("Wrong point coordinates.");
								}

								points[i] = new Point(x, y);
							}
						}
					}
				} else {
					return null;
				}
			} catch(FileNotFoundException e) {
				System.out.println("File not found");
			}
		}

		return points;
	}

	public double interpFunctionValue() {}


}
