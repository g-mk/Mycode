#pragma once

namespace MacroSubs {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			Input=gcnew array<String^> (80);
			Output =gcnew array<String^> (50);
			Output = nullptr;
			MacDef = gcnew array<String^> (50);
			Dummy = gcnew array<String^> (10);
			Actual = gcnew array<String^> (10);
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	protected: 
	private: System::Windows::Forms::RichTextBox^  richTextBox2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(13, 42);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(348, 327);
			this->richTextBox1->TabIndex = 0;
			this->richTextBox1->Text = L"";
			// 
			// richTextBox2
			// 
			this->richTextBox2->Location = System::Drawing::Point(393, 42);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->Size = System::Drawing::Size(370, 327);
			this->richTextBox2->TabIndex = 1;
			this->richTextBox2->Text = L"";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button1->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 14.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(331, 387);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(93, 40);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Expand";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label1->Font = (gcnew System::Drawing::Font(L"Rosewood Std Regular", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::GhostWhite;
			this->label1->Location = System::Drawing::Point(131, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(123, 22);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Source Code";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label2->Font = (gcnew System::Drawing::Font(L"Rosewood Std Regular", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::GhostWhite;
			this->label2->Location = System::Drawing::Point(509, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(141, 22);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Expanded Code";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(775, 439);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->richTextBox2);
			this->Controls->Add(this->richTextBox1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->Text = L"PreProcessor";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: array<String^>^Input;
				 array<String^>^Output;
				 array<String^>^MacDef;
				 array<String^> ^Dummy;
				 array<String^>^Actual;
				 array<String^>^Token;
				 array<String^>^Temp;
				 static int maclen=0;
				 static String^ MacName="\0";

	private: System::Int16 macSep(array<String^>^In,int i)
		 {
			 int pos;
			 while (In[i]->EndsWith("\\"))
				{
					pos=In[i]->IndexOf("\\");
					In[i] = In[i]->Remove(pos);
					MacDef[++maclen]=In[i];
				    i++;
				}
			MacDef[++maclen]=In[i];
			return i;
						 
		 }
	private: System::Void replaceMacCall()
	{
				 if (maclen >= 1)
				 {
					 for (int i = 0; i <= maclen; i++)
					 {
						 String^ SubsMac;
						 SubsMac = SubsMac->Copy(MacDef[i]);
						 //SubsMac = MacDef[i];
						 for (int j = 0; j < Dummy->Length; j++)
						 { 
							 SubsMac = SubsMac->Replace(Dummy[j], Actual[j]);
						 }
						 richTextBox2->AppendText(SubsMac);
						 richTextBox2->AppendText("\n");
					 }
				 }
				 else
				 {
					 String^ SubsMac;
					 //SubsMac = MacDef[i];
					 SubsMac = SubsMac->Copy(MacDef[0]);
					 for (int i = 0; i < Dummy->Length; i++)
					 {
						 SubsMac = SubsMac->Replace(Dummy[i], Actual[i]);
		
					 }
					 richTextBox2->AppendText(SubsMac);
				 }

		}

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 richTextBox2->Clear();
				// Dummy = nullptr;
				 //Actual = nullptr;
				 int Length;
				 Input=richTextBox1->Lines;
				 Length = richTextBox1->Lines->Length;
				 for (int i = 0; i < Length; i++)
				 {

					 Token = Input[i]->Split(' ');
					 if (Token[0]->Equals("#define"))
					 {
						 Temp = Token[1]->Split('(');
						 MacName = Temp[0];
						 Dummy = Temp[1]->Split(',');
						 int len = Dummy->Length;
						 int del = Dummy[len - 1]->IndexOf(")");
						 Dummy[len - 1] = Dummy[len - 1]->Remove(del);
						 if (Input[i]->EndsWith("\\"))
						 {
							 MacDef[maclen] = Token[2];
							 i = macSep(Input, i + 1);
						 }
						 else
							 MacDef[maclen] = Token[2];
					 }
					 else if (Input[i]->Contains(MacName))
					 {
						 String^ Token = Input[i];
						 Temp = Token->Split(' ');
						 for (int i = 0; i < Temp->Length; i++)
						 {
							 if (Temp[i]->Contains(MacName))
							 {
								 array<String^>^inter = Temp[i]->Split('(');
								 Actual = inter[1]->Split(',');
								 int len = Actual->Length;
								 int del = Actual[len - 1]->IndexOf(")");
								 Actual[len - 1] = Actual[len - 1]->Remove(del);
								 replaceMacCall();
								 
							 }
							 else
							 {
								 if (i != 0)
									richTextBox2->AppendText(" ");
								 richTextBox2->AppendText(Temp[i]);
							 }
						 }
						 richTextBox2->AppendText("\n");
					 }
					 else
					 {
						 richTextBox2->AppendText(Input[i]);
						 richTextBox2->AppendText("\n");
					 }
				 }
				 for (int i = 0; i <= maclen; i++)
				 {
					 MacDef[i] = "";
					
				 }
				 maclen = 0;
			 }
	};
}
