#pragma once

namespace TextEditor {
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
			InitializeComponent();
			FName = "";
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
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  newToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  openToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveAsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  editToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  cutToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  copyToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  pasteToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  findToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^  formatToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  wordWrapToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^  underlineToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  fontColorToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  undoToolStripMenuItem;



	private:
		/// <summary>
		
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::ToolStripMenuItem^  fontToolStripMenuItem;
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->newToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveAsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->editToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->cutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->copyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pasteToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->findToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->undoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->formatToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->wordWrapToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->underlineToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->fontColorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			fontToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// fontToolStripMenuItem
			// 
			fontToolStripMenuItem->Name = L"fontToolStripMenuItem";
			fontToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::I));
			fontToolStripMenuItem->Size = System::Drawing::Size(202, 22);
			fontToolStripMenuItem->Text = L"Italic";
			fontToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::fontToolStripMenuItem_Click);
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(2, 23);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(632, 227);
			this->richTextBox1->TabIndex = 0;
			this->richTextBox1->Text = L"";
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->fileToolStripMenuItem,
					this->editToolStripMenuItem, this->formatToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(635, 24);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->newToolStripMenuItem,
					this->openToolStripMenuItem, this->saveToolStripMenuItem, this->saveAsToolStripMenuItem, this->exitToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// newToolStripMenuItem
			// 
			this->newToolStripMenuItem->Name = L"newToolStripMenuItem";
			this->newToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::N));
			this->newToolStripMenuItem->Size = System::Drawing::Size(186, 22);
			this->newToolStripMenuItem->Text = L"New";
			this->newToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::newToolStripMenuItem_Click);
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::O));
			this->openToolStripMenuItem->Size = System::Drawing::Size(186, 22);
			this->openToolStripMenuItem->Text = L"Open";
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::openToolStripMenuItem_Click);
			// 
			// saveToolStripMenuItem
			// 
			this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
			this->saveToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::S));
			this->saveToolStripMenuItem->Size = System::Drawing::Size(186, 22);
			this->saveToolStripMenuItem->Text = L"Save";
			this->saveToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::saveToolStripMenuItem_Click);
			// 
			// saveAsToolStripMenuItem
			// 
			this->saveAsToolStripMenuItem->Name = L"saveAsToolStripMenuItem";
			this->saveAsToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Shift)
				| System::Windows::Forms::Keys::S));
			this->saveAsToolStripMenuItem->Size = System::Drawing::Size(186, 22);
			this->saveAsToolStripMenuItem->Text = L"Save As";
			this->saveAsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::saveAsToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::F4));
			this->exitToolStripMenuItem->Size = System::Drawing::Size(186, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::exitToolStripMenuItem_Click);
			// 
			// editToolStripMenuItem
			// 
			this->editToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->cutToolStripMenuItem,
					this->copyToolStripMenuItem, this->pasteToolStripMenuItem, this->findToolStripMenuItem, this->undoToolStripMenuItem
			});
			this->editToolStripMenuItem->Name = L"editToolStripMenuItem";
			this->editToolStripMenuItem->Size = System::Drawing::Size(39, 20);
			this->editToolStripMenuItem->Text = L"Edit";
			// 
			// cutToolStripMenuItem
			// 
			this->cutToolStripMenuItem->Name = L"cutToolStripMenuItem";
			this->cutToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::X));
			this->cutToolStripMenuItem->Size = System::Drawing::Size(144, 22);
			this->cutToolStripMenuItem->Text = L"Cut";
			this->cutToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::cutToolStripMenuItem_Click);
			// 
			// copyToolStripMenuItem
			// 
			this->copyToolStripMenuItem->Name = L"copyToolStripMenuItem";
			this->copyToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::C));
			this->copyToolStripMenuItem->Size = System::Drawing::Size(144, 22);
			this->copyToolStripMenuItem->Text = L"Copy";
			this->copyToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::copyToolStripMenuItem_Click);
			// 
			// pasteToolStripMenuItem
			// 
			this->pasteToolStripMenuItem->Name = L"pasteToolStripMenuItem";
			this->pasteToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::V));
			this->pasteToolStripMenuItem->Size = System::Drawing::Size(144, 22);
			this->pasteToolStripMenuItem->Text = L"Paste";
			this->pasteToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::pasteToolStripMenuItem_Click);
			// 
			// findToolStripMenuItem
			// 
			this->findToolStripMenuItem->Name = L"findToolStripMenuItem";
			this->findToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::F));
			this->findToolStripMenuItem->Size = System::Drawing::Size(144, 22);
			this->findToolStripMenuItem->Text = L"Find";
			this->findToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::findToolStripMenuItem_Click);
			// 
			// undoToolStripMenuItem
			// 
			this->undoToolStripMenuItem->Name = L"undoToolStripMenuItem";
			this->undoToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Z));
			this->undoToolStripMenuItem->Size = System::Drawing::Size(144, 22);
			this->undoToolStripMenuItem->Text = L"Undo";
			this->undoToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::undoToolStripMenuItem_Click);
			// 
			// formatToolStripMenuItem
			// 
			this->formatToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->wordWrapToolStripMenuItem,
					fontToolStripMenuItem, this->underlineToolStripMenuItem, this->fontColorToolStripMenuItem
			});
			this->formatToolStripMenuItem->Name = L"formatToolStripMenuItem";
			this->formatToolStripMenuItem->Size = System::Drawing::Size(57, 20);
			this->formatToolStripMenuItem->Text = L"Format";
			// 
			// wordWrapToolStripMenuItem
			// 
			this->wordWrapToolStripMenuItem->Name = L"wordWrapToolStripMenuItem";
			this->wordWrapToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::B));
			this->wordWrapToolStripMenuItem->Size = System::Drawing::Size(202, 22);
			this->wordWrapToolStripMenuItem->Text = L"Bold";
			this->wordWrapToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::wordWrapToolStripMenuItem_Click);
			// 
			// underlineToolStripMenuItem
			// 
			this->underlineToolStripMenuItem->Name = L"underlineToolStripMenuItem";
			this->underlineToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::U));
			this->underlineToolStripMenuItem->Size = System::Drawing::Size(202, 22);
			this->underlineToolStripMenuItem->Text = L"Underline";
			this->underlineToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::underlineToolStripMenuItem_Click);
			// 
			// fontColorToolStripMenuItem
			// 
			this->fontColorToolStripMenuItem->Name = L"fontColorToolStripMenuItem";
			this->fontColorToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Shift)
				| System::Windows::Forms::Keys::F));
			this->fontColorToolStripMenuItem->Size = System::Drawing::Size(202, 22);
			this->fontColorToolStripMenuItem->Text = L"Font Color";
			this->fontColorToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::fontColorToolStripMenuItem_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(635, 262);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->menuStrip1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"Text Editor";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		String^ FName;

	private: System::Void openToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 OpenFileDialog oFile;
				 if(oFile.ShowDialog() == System::Windows::Forms::DialogResult::OK && oFile.FileName->Length > 0)
				 {
					 FName=oFile.FileName;
					 richTextBox1->LoadFile(oFile.FileName,RichTextBoxStreamType::PlainText);
				 }
			 }

private: System::Void saveAsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				SaveFileDialog sFile;
				if(sFile.ShowDialog() == System::Windows::Forms::DialogResult::OK && sFile.FileName->Length >0)
				{
					FName=sFile.FileName;
					richTextBox1->SaveFile(sFile.FileName,RichTextBoxStreamType::PlainText);
				}

		 }

private: System::Void newToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 richTextBox1->Clear();
			 FName="";
		 }
private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Close();
		 }
private: System::Void cutToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 richTextBox1->Cut();
		 }
private: System::Void copyToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 richTextBox1->Copy();
		 }
private: System::Void pasteToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 richTextBox1->Paste();
		 }


private: System::Void saveToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(FName->Equals(""))
			 {
				 SaveFileDialog sFile;
				if(sFile.ShowDialog() == System::Windows::Forms::DialogResult::OK && sFile.FileName->Length >0)
				{
					FName=sFile.FileName;
					richTextBox1->SaveFile(sFile.FileName,RichTextBoxStreamType::PlainText);
				}
			 }

			 else
			 {
				 richTextBox1->SaveFile(FName,RichTextBoxStreamType::PlainText);
			 }

		 }
private: System::Void wordWrapToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (richTextBox1->SelectionFont != nullptr)
			 {
				 System::Drawing::Font^ currentFont = richTextBox1->SelectionFont;
				 System::Drawing::FontStyle newFontStyle;

				 if (richTextBox1->SelectionFont->Bold == false && (richTextBox1->SelectionFont->Underline == true && richTextBox1->SelectionFont->Italic == true))
				 {
					 newFontStyle = FontStyle::Bold + FontStyle::Italic + FontStyle::Underline;
				 }
				 else if (richTextBox1->SelectionFont->Bold == false && (richTextBox1->SelectionFont->Underline == true || richTextBox1->SelectionFont->Italic == true))
				 {
					 if (richTextBox1->SelectionFont->Underline == true)
					 {
						 newFontStyle = FontStyle::Bold + FontStyle::Underline;
					 }
					 else if (richTextBox1->SelectionFont->Italic==true)
					 {
						 newFontStyle = FontStyle::Bold + FontStyle::Italic;
					 }
				 }
				 else if (richTextBox1->SelectionFont->Bold == true && (richTextBox1->SelectionFont->Underline == true && richTextBox1->SelectionFont->Italic == true))
				 {
					 newFontStyle = FontStyle::Underline + FontStyle::Italic;
				 }
				 else if (richTextBox1->SelectionFont->Bold == true && (richTextBox1->SelectionFont->Underline == true || richTextBox1->SelectionFont->Italic == true))
				 {
					 if (richTextBox1->SelectionFont->Underline == true)
					 {
						 newFontStyle =  FontStyle::Underline;
					 }
					 else if (richTextBox1->SelectionFont->Italic == true)
					 {
						 newFontStyle = FontStyle::Italic;
					 }
				 }
				 else if (richTextBox1->SelectionFont->Bold == false)
				 {
					 newFontStyle = FontStyle::Bold;
				 }
				 else
				 {
					 newFontStyle = FontStyle::Regular;
				 }
				 richTextBox1->SelectionFont = gcnew System::Drawing::Font(currentFont->FontFamily, currentFont->Size, newFontStyle);
			 }
		 }
private: System::Void fontToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (richTextBox1->SelectionFont != nullptr)
			 {
				 System::Drawing::Font^ currentFont = richTextBox1->SelectionFont;
				 System::Drawing::FontStyle newFontStyle;
				 if (richTextBox1->SelectionFont->Italic == false && (richTextBox1->SelectionFont->Underline == true && richTextBox1->SelectionFont->Bold == true))
				 {
					 newFontStyle = FontStyle::Italic + FontStyle::Bold + FontStyle::Underline;
				 }
				 else if (richTextBox1->SelectionFont->Italic == false && (richTextBox1->SelectionFont->Underline == true || richTextBox1->SelectionFont->Bold == true))
				 {
					 if (richTextBox1->SelectionFont->Underline == true)
					 {
						 newFontStyle = FontStyle::Italic + FontStyle::Underline;
					 }
					 else if (richTextBox1->SelectionFont->Bold == true)
					 {
						 newFontStyle = FontStyle::Italic + FontStyle::Bold;
					 }
				 }
				 else if (richTextBox1->SelectionFont->Italic == true && (richTextBox1->SelectionFont->Underline == true && richTextBox1->SelectionFont->Bold == true))
				 {
					 newFontStyle = FontStyle::Underline + FontStyle::Bold;
				 }
				 else if (richTextBox1->SelectionFont->Italic == true && (richTextBox1->SelectionFont->Underline == true || richTextBox1->SelectionFont->Bold == true))
				 {
					 if (richTextBox1->SelectionFont->Underline == true)
					 {
						 newFontStyle = FontStyle::Underline;
					 }
					 else if (richTextBox1->SelectionFont->Bold == true)
					 {
						 newFontStyle = FontStyle::Bold;
					 }
				 }
				 else if (richTextBox1->SelectionFont->Italic == false)
				 {
					 newFontStyle = FontStyle::Italic;
				 }
				 else
				 {
					 newFontStyle = FontStyle::Regular;
				 }
				 richTextBox1->SelectionFont = gcnew System::Drawing::Font(currentFont->FontFamily, currentFont->Size, newFontStyle);
			 }
		 }
private: System::Void fontColorToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 ColorDialog colorDialog1;

			 colorDialog1.Color = richTextBox1->SelectionColor;

			 if (colorDialog1.ShowDialog() == System::Windows::Forms::DialogResult::OK &&
				 colorDialog1.Color != richTextBox1->SelectionColor)
			 {
				 richTextBox1->SelectionColor = colorDialog1.Color;
			 }
		 }
private: System::Void underlineToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (richTextBox1->SelectionFont != nullptr)
			 {
				 System::Drawing::Font^ currentFont = richTextBox1->SelectionFont;
				 System::Drawing::FontStyle newFontStyle;


				 if (richTextBox1->SelectionFont->Underline == false && (richTextBox1->SelectionFont->Italic == true && richTextBox1->SelectionFont->Bold == true))
				 {
					 newFontStyle = FontStyle::Italic + FontStyle::Bold + FontStyle::Underline;
				 }
				 else if (richTextBox1->SelectionFont->Underline == false && (richTextBox1->SelectionFont->Italic == true || richTextBox1->SelectionFont->Bold == true))
				 {
					 if (richTextBox1->SelectionFont->Italic == true)
					 {
						 newFontStyle = FontStyle::Italic + FontStyle::Underline;
					 }
					 else if (richTextBox1->SelectionFont->Bold == true)
					 {
						 newFontStyle = FontStyle::Bold + FontStyle::Underline;
					 }
				 }
				 else if (richTextBox1->SelectionFont->Underline == true && (richTextBox1->SelectionFont->Italic == true && richTextBox1->SelectionFont->Bold == true))
				 {
					 newFontStyle = FontStyle::Italic + FontStyle::Bold;
				 }
				 else if (richTextBox1->SelectionFont->Underline == true && (richTextBox1->SelectionFont->Italic == true || richTextBox1->SelectionFont->Bold == true))
				 {
					 if (richTextBox1->SelectionFont->Italic == true)
					 {
						 newFontStyle = FontStyle::Italic;
					 }
					 else if (richTextBox1->SelectionFont->Bold == true)
					 {
						 newFontStyle = FontStyle::Bold;
					 }
				 }
				 else if (richTextBox1->SelectionFont->Underline == false)
				 {
					 newFontStyle = FontStyle::Underline;
				 }
				 else
				 {
					 newFontStyle = FontStyle::Regular;
				 }
				 richTextBox1->SelectionFont = gcnew System::Drawing::Font(currentFont->FontFamily, currentFont->Size, newFontStyle);
			 }
		 }
private: System::Void findToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 richTextBox1->Find("HI");
}
private: System::Void undoToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 richTextBox1->Undo();
}
};

}
