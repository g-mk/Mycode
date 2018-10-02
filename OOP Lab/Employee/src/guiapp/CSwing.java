package guiapp;
import payrollmanagement.*;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.GroupLayout.Alignment;
import javax.swing.border.EmptyBorder;

public class CSwing extends JFrame {

	private JPanel contentPane;
	private JTextField textField;
	private JLabel lblDateOfBirth;
	private JLabel lblMonth;
	private JComboBox comboBox_1;
	private JLabel lblYear;
	private JComboBox comboBox_2;
	private JRadioButton rdbtnWaged;
	private JLabel lblBasicPay;
	private JTextField textField_1;
	private JTextField textField_2;
	private JTextField textField_3;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					CSwing frame = new CSwing();
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the frame.
	 */
	public CSwing() {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 450, 300);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		
		textField = new JTextField();
		textField.setBounds(63, 61, 114, 19);
		textField.setColumns(10);
		
		
		JLabel lblNewLabel = new JLabel("Name:");
		lblNewLabel.setBounds(12, 63, 70, 15);
		
		lblDateOfBirth = new JLabel("Date:");
		lblDateOfBirth.setBounds(12, 92, 95, 15);
		
		JComboBox comboBox = new JComboBox();
		comboBox.setBounds(63, 87, 32, 24);
		
		lblMonth = new JLabel("Month:");
		lblMonth.setBounds(107, 92, 70, 15);
		
		comboBox_1 = new JComboBox();
		comboBox_1.setBounds(167, 87, 32, 24);
		
		lblYear = new JLabel("Year:");
		lblYear.setBounds(208, 92, 70, 15);
		
		comboBox_2 = new JComboBox();
		comboBox_2.setBounds(246, 87, 32, 24);
		
		JRadioButton rdbtnSalariedEmployee = new JRadioButton("Salaried");
		rdbtnSalariedEmployee.setBounds(8, 119, 87, 23);
		
		rdbtnWaged = new JRadioButton("Waged");
		rdbtnWaged.setBounds(107, 119, 149, 23);
		
		ButtonGroup group = new ButtonGroup();
		group.add(rdbtnSalariedEmployee);
		group.add(rdbtnWaged);
		
                lblBasicPay = new JLabel("Basic Pay:");
		lblBasicPay.setBounds(12, 153, 95, 15);
		
		textField_1 = new JTextField();
		textField_1.setBounds(94, 150, 114, 19);
		textField_1.setColumns(10);
		
		JButton btnSubmit = new JButton("Submit");
		btnSubmit.setBounds(218, 235, 117, 25);
		
		JButton btnSetotamount = new JButton("SetOTAmount:");
		btnSetotamount.setBounds(12, 180, 117, 19);
		btnSetotamount.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent action) {
				
			 JOptionPane.showMessageDialog(null, "OK");
			}
		});
		
		textField_2 = new JTextField();
		textField_2.setBounds(141, 181, 114, 19);
		textField_2.setColumns(10);
		
		JButton btnSetbonus = new JButton("SetBonus:");
		btnSetbonus.setBounds(12, 217, 117, 19);
		
		textField_3 = new JTextField();
		textField_3.setBounds(142, 212, 114, 19);
		textField_3.setColumns(10);
		
		JLabel lblPayRollManagement = new JLabel("Pay Roll Management");
		lblPayRollManagement.setBounds(167, 12, 168, 15);
		contentPane.setLayout(null);
		contentPane.add(textField);
		contentPane.add(lblNewLabel);
		contentPane.add(lblDateOfBirth);
		contentPane.add(comboBox);
		contentPane.add(lblMonth);
		contentPane.add(comboBox_1);
		contentPane.add(lblYear);
		contentPane.add(comboBox_2);
		contentPane.add(rdbtnSalariedEmployee);
		contentPane.add(rdbtnWaged);
		contentPane.add(lblBasicPay);
		contentPane.add(textField_1);
		contentPane.add(btnSubmit);
		contentPane.add(btnSetotamount);
		contentPane.add(textField_2);
		contentPane.add(btnSetbonus);
		contentPane.add(textField_3);
		contentPane.add(lblPayRollManagement);
	}

}
