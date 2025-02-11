package main;

import java.io.IOException;

public class Pilot {

	public static void main(String[] args) {

		Generator g = new Generator();
		Translator t = new Translator();
		try {
			g.doEncrypt();
			t.doDecrypt();
		} catch (IOException e) {
			e.printStackTrace();
		}

	}

}
