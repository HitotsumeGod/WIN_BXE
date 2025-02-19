package Generator.main;

import java.io.IOException;
import java.io.Console;

public class Pilot {

	public static void main(String[] args) {
		
		Console con = System.console();
		final long startTime = System.currentTimeMillis();
		Generator g = new Generator();
		try {
			g.doEncrypt();
		} catch (IOException e) {
			e.printStackTrace();
		}
		final long endTime = System.currentTimeMillis();
		System.out.println("Total execution time: " + (endTime - startTime) / 1000 + " seconds.");

	}

}
