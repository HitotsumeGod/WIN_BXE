package main;

import java.io.IOException;

public class Pilot {

	public static void main(String[] args) {
		
		Console con = System.console();
		final long startTime = System.currentTimeMillis();
		Generator g = new Generator();
		Translator t = new Translator();
		try {
			g.doEncrypt();
			t.doDecrypt();
		} catch (IOException e) {
			e.printStackTrace();
		}
		final long endTime = System.currentTimeMillis();
		System.out.println("Total execution time: " + (endTime - startTime) / 1000 + " seconds.");

	}

}
