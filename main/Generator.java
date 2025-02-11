package main;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.security.NoSuchAlgorithmException;
import java.security.SecureRandom;

class Generator {
	
	private static final char NIGHT = '`';
	private static final char DOUBLE_NIGHT = '@';
	private static final char SPACE = '|';
	private static final int UPPERLIMIT = 25;
	private static final String NOCK = "WIN_BXE";
	private int key;
	private SecureRandom srand;
	
	Generator() {
		
		try {
			srand = SecureRandom.getInstanceStrong();
		} catch (NoSuchAlgorithmException na) {
			na.printStackTrace();
		}
		
	}
	
	private String convert(char c) {
		
		String result = "";
		switch(c) {
		
		case 'a':
			result += '<';
			for (int i = 0; i < (key + 2); i++)
				result += '$';
			for (int i = 0; i < (key * 2); i++)
				result += '^';
			break;
		case 'b':
			result += "??";
			for (int i = 0; i < key; i++)
				result += '!';
			break;
		case 'c':
			result += "^^^";
			for (int i = 0; i < (key + 1); i++)
				result += '!';
			break;
		case 'd':
			for (int i = 0; i < key; i++)
				result += '*';
			for (int i = 0; i < key; i++)
				result += '<';
			for (int i = 0; i < (key + 3); i++)
				result += '*';
			break;
		case 'e':
			for (int i = 0; i < (key + 5); i++)
				result += '%';
			result += "!$!";
			break;
		case 'f':
			result += ">>>";
			for (int i = 0; i < key; i++)
				result += '$';
			result += '!';
			break;
		case 'g':
			for (int i = 0; i < ((key * 2) + 24); i++)
				result += '*';
			result += "&<";
			break;
		case 'h':
			for (int i = 0; i < key; i++)
				result += '!';
			result += "$$!";
			break;
		case 'i':
			result += "%^";
			for (int i = 0; i < key; i++)
				result += '^';
			result += '%';
			break;
		case 'j':
			for (int i = 0; i < ((key / 2) + 16); i++)
				result+= '?';
			result += "*^^*";
			break;
		case 'k':
			for (int i = 0; i < key; i++)
				result += '^';
			for (int i = 0; i < key; i++)
				result += '*';
			result += "&&*";
			break;
		case 'l':
			result += "!!$$%%^^^";
			for (int i = 0; i < (key + 7); i++)
				result += '>';
			break;
		case 'm':
			for (int i = 0; i < key; i++)
				result += '&';
			result += '^';
			for (int i = 0; i < key; i++)
				result += '$';
			break;
		case 'n':
			result += "&^";
			for (int i = 0; i < (key * 3); i++)
				result += '^';
			break;
		case 'o':
			result += "<<";
			for (int i = 0; i < key; i++)
				result += '*';
			result += ">>&";
			break;
		case 'p':
			result += "<<<<";
			for (int i = 0; i < key; i++)
				result += '!';
			break;
		case 'q':
			for (int i = 0; i < (key - (key / 2) + (key / 4)); i++)
				result += '*';
			result += "&^";
			break;
		case 'r':
			result += "!$$";
			for (int i = 0; i < key; i++)
				result += '!';
			break;
		case 's':
			result += "?>";
			for (int i = 0; i < (key + 22); i++)
				result += '?';
			result += "!!";
			break;
		case 't':
			result += "%%";
			for (int i = 0; i < (key + 1); i++)
				result += '&';
			break;
		case 'u':
			result += "!!!!<";
			for (int i = 0; i < key; i++)
				result += '$';
			for (int i = 0; i < key; i++)
				result += '<';
			for (int i = 0; i < key; i++)
				result += '!';
			break;
		case 'v':
			result += "*^^";
			for (int i = 0; i < (key + 12); i++)
				result += '>';
			break;
		case 'w':
			for (int i = 0; i < (key * 4); i++)
				result += '$';
			break;
		case 'x':
			result += '<';
			for (int i = 0; i < key; i++)
				result += ">";
			result += "$$";
			for (int i = 0; i < key; i++)
				result += '%';
			break;
		case 'y':
			result += "!>>$";
			for (int i = 0; i < (key * 2); i++)
				result += '!';
			break;
		case 'z':
			result += "????!";
			for (int i = 0; i < key; i++)
				result += '$';
			result += '?';
			break;
		case ' ':
			result = "";
		case '\t':
			result = "";
		case '\n':
			result = "";
		case '.':
			result = "";
		case ',':
			result = "";
		case '"':
			result = "";
		case '`':
			result = "";
		case '?':
			result = "";
		case '-':
			result = "";
			break;
		default:
			if (Character.isWhitespace(c)) {
				result = "";
			} else {
				System.out.println(c + "Only alphabet characters permitted. Quitting.");
				System.exit(1);
			}
		
		}
		return result;
		
	}
	
	public void doEncrypt() throws IOException {
		
		File inptf = new File("g_files/inptf");
		File outptf = new File("g_files/outptf");
		String toTranslate = "";
		int c;
		FileWriter clearit = new FileWriter(outptf);
		clearit.write("");
		clearit.close();
		key = srand.nextInt(UPPERLIMIT) + 1;
		System.out.println(key + "g");
		BufferedReader bfr = new BufferedReader(new FileReader(inptf));
		BufferedWriter bwr = new BufferedWriter(new FileWriter(outptf, true));
		while ((c = bfr.read()) != -1)
			toTranslate += (char) c;
		bwr.write(NOCK);
		for (int i = 0; i < toTranslate.length(); i++) {
			bwr.write(convert(Character.toLowerCase(toTranslate.charAt(i))));
			for (int il = 0; il < (key + 3); il++)
				bwr.write(SPACE);
			int night = srand.nextInt(4);
			switch (night) {
			case 0:
				break;
			case 1:
				for (int i2 = 0; i2 < (key + 14); i2++)
					bwr.write('`');
				break;
			case 2:
				bwr.write("`");
				break;
			case 3:
				bwr.write('@');
				break;
			case 4:
				break;
			case 5:
				break;
			}
		}
		bfr.close();
		bwr.close();
		
		
	}

}
