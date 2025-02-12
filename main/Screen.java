package main;

import java.io.IOException;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

class Screen extends JFrame {

	private Generator g;
	private Translator t;
	private JPanel barPanel;
	private JProgressBar prog;
	private final Screen instance;

	private class Actioner implements ActionListener {
	
		private final Screen s;
		private final JButton b;
		private double startTime, endTime;
		private Thread t1;
	
		private Actioner(Screen s, JButton b) { this.s = s; this.b = b; }
	
		public void actionPerformed(ActionEvent e) {
		
			try {
				if (b.getName().equals("generate")) {
					System.out.println("Encrypting data...");
					startTime = System.currentTimeMillis();
					t1 = new Thread(g);
					t1.start();
					t1.join();
					endTime = System.currentTimeMillis();
					System.out.println("Data encrypted in " + (endTime - startTime) + " milliseconds.");
				} else {
					System.out.println("Decrypting data...");
					startTime = System.currentTimeMillis();
					t1 = new Thread(t);
					t1.start();
					t1.join();
					endTime = System.currentTimeMillis();
					System.out.println("Data decrypted in " + (endTime - startTime) / 1000 + " seconds.");
				}
			} catch (IOException i) {
				i.printStackTrace();
			}
		
		}
	
	}

	Screen() {
	
		instance = this;
		JPanel textPanel = new JPanel();
		JPanel buttonPanel = new JPanel();
		JLabel l1 = new JLabel("WIN_BXE TRANSLATOR/GENERATOR");
		JLabel l2 = new JLabel("Developed by Super Peter Naylor");
		JButton generate = new JButton("Press to generate encoded text.");
		JButton translate = new JButton("Press to translate encoded text.");
		Font newFont = new Font("Serif", Font.BOLD, 24);
		l1.setFont(newFont);
		l2.setFont(newFont);
		generate.setName("generate");
		translate.setName("translate");
		generate.setFont(newFont);
		translate.setFont(newFont);
		generate.addActionListener(new Actioner(generate));
		translate.addActionListener(new Actioner(translate));
		textPanel.setLayout(new BoxLayout(textPanel, BoxLayout.Y_AXIS));
		buttonPanel.setLayout(new FlowLayout());
		textPanel.add(l1);
		textPanel.add(l2);
		buttonPanel.add(generate);
		buttonPanel.add(translate);
		this.setSize(400, 600);
		this.setLayout(new BoxLayout(getContentPane(), BoxLayout.Y_AXIS));
		this.add(textPanel);
		this.add(buttonPanel);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.getContentPane().setBackground(Color.black);
		this.pack();

	}
	
	public void getInstance() {
	
		return instance;
	
	}
	
	public void getBar() {
	
		return prog;
	
	}
	
	public void appear() { this.setVisible(true); }

}
