#pragma once

#include <Context.h>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace paritygraphicalconfigurator {

	/// <summary>
	/// Zusammenfassung f�r Configurator
	///
	/// Warnung: Wenn Sie den Namen dieser Klasse �ndern, m�ssen Sie auch
	///          die Ressourcendateiname-Eigenschaft f�r das Tool zur Kompilierung verwalteter Ressourcen �ndern,
	///          das allen RESX-Dateien zugewiesen ist, von denen diese Klasse abh�ngt.
	///          Anderenfalls k�nnen die Designer nicht korrekt mit den lokalisierten Ressourcen
	///          arbeiten, die diesem Formular zugewiesen sind.
	/// </summary>
	public ref class Configurator : public System::Windows::Forms::Form
	{
	public:
		Configurator(void)
		{
			InitializeComponent();
			context_ = NULL;
			initial_ = NULL;
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~Configurator()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ToolStrip^  tsToolbar;
	private: System::Windows::Forms::ToolStripButton^  tbtnNew;
	private: System::Windows::Forms::ToolStripButton^  tbtnOpen;
	private: System::Windows::Forms::ToolStripButton^  tbtnSave;
	private: System::Windows::Forms::ListView^  lvSettings;
	private: System::Windows::Forms::ImageList^  ilImages;
	private: System::Windows::Forms::ColumnHeader^  colName;
	private: System::Windows::Forms::ColumnHeader^  colType;
	private: System::Windows::Forms::ColumnHeader^  colValue;
	private: System::Windows::Forms::ColumnHeader^  colDefaultValue;
	private: System::Windows::Forms::OpenFileDialog^  dlgOpenFile;
	private: System::Windows::Forms::SaveFileDialog^  dlgSaveFile;
	private: System::Windows::Forms::MenuStrip^  msMainMenu;
	private: System::Windows::Forms::ToolStripMenuItem^  mnuFile;
	private: System::Windows::Forms::ToolStripMenuItem^  mnuNew;
	private: System::Windows::Forms::ToolStripMenuItem^  mnuOpen;
	private: System::Windows::Forms::ToolStripMenuItem^  mnuSaveAs;
	private: System::Windows::Forms::StatusStrip^  stStatus;
	private: System::Windows::Forms::ToolStripStatusLabel^  stStatusLabel;


	private: System::ComponentModel::IContainer^  components;
	protected: 

	protected: 




	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode f�r die Designerunterst�tzung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor ge�ndert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Configurator::typeid));
			System::Windows::Forms::ListViewGroup^  listViewGroup1 = (gcnew System::Windows::Forms::ListViewGroup(L"Changed Settings", System::Windows::Forms::HorizontalAlignment::Left));
			System::Windows::Forms::ListViewGroup^  listViewGroup2 = (gcnew System::Windows::Forms::ListViewGroup(L"Unchanged Settings", System::Windows::Forms::HorizontalAlignment::Left));
			this->tsToolbar = (gcnew System::Windows::Forms::ToolStrip());
			this->tbtnNew = (gcnew System::Windows::Forms::ToolStripButton());
			this->tbtnOpen = (gcnew System::Windows::Forms::ToolStripButton());
			this->tbtnSave = (gcnew System::Windows::Forms::ToolStripButton());
			this->lvSettings = (gcnew System::Windows::Forms::ListView());
			this->colName = (gcnew System::Windows::Forms::ColumnHeader(0));
			this->colValue = (gcnew System::Windows::Forms::ColumnHeader());
			this->colType = (gcnew System::Windows::Forms::ColumnHeader());
			this->colDefaultValue = (gcnew System::Windows::Forms::ColumnHeader());
			this->ilImages = (gcnew System::Windows::Forms::ImageList(this->components));
			this->dlgOpenFile = (gcnew System::Windows::Forms::OpenFileDialog());
			this->dlgSaveFile = (gcnew System::Windows::Forms::SaveFileDialog());
			this->msMainMenu = (gcnew System::Windows::Forms::MenuStrip());
			this->mnuFile = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mnuNew = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mnuOpen = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mnuSaveAs = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->stStatus = (gcnew System::Windows::Forms::StatusStrip());
			this->stStatusLabel = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->tsToolbar->SuspendLayout();
			this->msMainMenu->SuspendLayout();
			this->stStatus->SuspendLayout();
			this->SuspendLayout();
			// 
			// tsToolbar
			// 
			this->tsToolbar->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->tbtnNew, this->tbtnOpen, 
				this->tbtnSave});
			this->tsToolbar->Location = System::Drawing::Point(0, 24);
			this->tsToolbar->Name = L"tsToolbar";
			this->tsToolbar->Size = System::Drawing::Size(815, 25);
			this->tsToolbar->TabIndex = 0;
			this->tsToolbar->Text = L"Toolbar";
			// 
			// tbtnNew
			// 
			this->tbtnNew->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->tbtnNew->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"tbtnNew.Image")));
			this->tbtnNew->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->tbtnNew->Name = L"tbtnNew";
			this->tbtnNew->Size = System::Drawing::Size(23, 22);
			this->tbtnNew->Text = L"Create a new Configuration";
			this->tbtnNew->Click += gcnew System::EventHandler(this, &Configurator::NewConfiguration);
			// 
			// tbtnOpen
			// 
			this->tbtnOpen->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->tbtnOpen->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"tbtnOpen.Image")));
			this->tbtnOpen->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->tbtnOpen->Name = L"tbtnOpen";
			this->tbtnOpen->Size = System::Drawing::Size(23, 22);
			this->tbtnOpen->Text = L"Open an existing Configuration";
			this->tbtnOpen->Click += gcnew System::EventHandler(this, &Configurator::OpenConfiguration);
			// 
			// tbtnSave
			// 
			this->tbtnSave->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->tbtnSave->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"tbtnSave.Image")));
			this->tbtnSave->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->tbtnSave->Name = L"tbtnSave";
			this->tbtnSave->Size = System::Drawing::Size(23, 22);
			this->tbtnSave->Text = L"Save current configuration";
			this->tbtnSave->Click += gcnew System::EventHandler(this, &Configurator::SaveConfiguration);
			// 
			// lvSettings
			// 
			this->lvSettings->AllowColumnReorder = true;
			this->lvSettings->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->lvSettings->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(4) {this->colName, this->colValue, 
				this->colType, this->colDefaultValue});
			this->lvSettings->FullRowSelect = true;
			this->lvSettings->GridLines = true;
			listViewGroup1->Header = L"Changed Settings";
			listViewGroup1->Name = L"lvgChanged";
			listViewGroup2->Header = L"Unchanged Settings";
			listViewGroup2->Name = L"lvgUnchanged";
			this->lvSettings->Groups->AddRange(gcnew cli::array< System::Windows::Forms::ListViewGroup^  >(2) {listViewGroup1, listViewGroup2});
			this->lvSettings->HideSelection = false;
			this->lvSettings->Location = System::Drawing::Point(0, 49);
			this->lvSettings->MultiSelect = false;
			this->lvSettings->Name = L"lvSettings";
			this->lvSettings->Size = System::Drawing::Size(815, 332);
			this->lvSettings->SmallImageList = this->ilImages;
			this->lvSettings->TabIndex = 1;
			this->lvSettings->UseCompatibleStateImageBehavior = false;
			this->lvSettings->View = System::Windows::Forms::View::Details;
			this->lvSettings->ItemActivate += gcnew System::EventHandler(this, &Configurator::EditItemDetails);
			// 
			// colName
			// 
			this->colName->Text = L"Name";
			this->colName->Width = 200;
			// 
			// colValue
			// 
			this->colValue->Text = L"Value";
			this->colValue->Width = 350;
			// 
			// colType
			// 
			this->colType->Text = L"Type";
			this->colType->Width = 100;
			// 
			// colDefaultValue
			// 
			this->colDefaultValue->Text = L"Default Value";
			this->colDefaultValue->Width = 150;
			// 
			// ilImages
			// 
			this->ilImages->ImageStream = (cli::safe_cast<System::Windows::Forms::ImageListStreamer^  >(resources->GetObject(L"ilImages.ImageStream")));
			this->ilImages->TransparentColor = System::Drawing::Color::Magenta;
			this->ilImages->Images->SetKeyName(0, L"Property");
			// 
			// dlgSaveFile
			// 
			this->dlgSaveFile->AddExtension = false;
			// 
			// msMainMenu
			// 
			this->msMainMenu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->mnuFile});
			this->msMainMenu->Location = System::Drawing::Point(0, 0);
			this->msMainMenu->Name = L"msMainMenu";
			this->msMainMenu->Size = System::Drawing::Size(815, 24);
			this->msMainMenu->TabIndex = 2;
			this->msMainMenu->Text = L"menuStrip1";
			// 
			// mnuFile
			// 
			this->mnuFile->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->mnuNew, this->mnuOpen, 
				this->mnuSaveAs});
			this->mnuFile->Name = L"mnuFile";
			this->mnuFile->Size = System::Drawing::Size(37, 20);
			this->mnuFile->Text = L"&File";
			// 
			// mnuNew
			// 
			this->mnuNew->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"mnuNew.Image")));
			this->mnuNew->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->mnuNew->Name = L"mnuNew";
			this->mnuNew->Size = System::Drawing::Size(124, 22);
			this->mnuNew->Text = L"&New";
			this->mnuNew->Click += gcnew System::EventHandler(this, &Configurator::NewConfiguration);
			// 
			// mnuOpen
			// 
			this->mnuOpen->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"mnuOpen.Image")));
			this->mnuOpen->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->mnuOpen->Name = L"mnuOpen";
			this->mnuOpen->Size = System::Drawing::Size(124, 22);
			this->mnuOpen->Text = L"&Open";
			this->mnuOpen->Click += gcnew System::EventHandler(this, &Configurator::OpenConfiguration);
			// 
			// mnuSaveAs
			// 
			this->mnuSaveAs->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"mnuSaveAs.Image")));
			this->mnuSaveAs->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->mnuSaveAs->Name = L"mnuSaveAs";
			this->mnuSaveAs->Size = System::Drawing::Size(124, 22);
			this->mnuSaveAs->Text = L"&Save as ...";
			this->mnuSaveAs->Click += gcnew System::EventHandler(this, &Configurator::SaveConfiguration);
			// 
			// stStatus
			// 
			this->stStatus->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->stStatusLabel});
			this->stStatus->Location = System::Drawing::Point(0, 380);
			this->stStatus->Name = L"stStatus";
			this->stStatus->Size = System::Drawing::Size(815, 22);
			this->stStatus->TabIndex = 3;
			this->stStatus->Text = L"\"...\"";
			// 
			// stStatusLabel
			// 
			this->stStatusLabel->Name = L"stStatusLabel";
			this->stStatusLabel->Size = System::Drawing::Size(16, 17);
			this->stStatusLabel->Text = L"...";
			// 
			// Configurator
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(815, 402);
			this->Controls->Add(this->stStatus);
			this->Controls->Add(this->lvSettings);
			this->Controls->Add(this->tsToolbar);
			this->Controls->Add(this->msMainMenu);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->msMainMenu;
			this->Name = L"Configurator";
			this->Text = L"Configurator";
			this->tsToolbar->ResumeLayout(false);
			this->tsToolbar->PerformLayout();
			this->msMainMenu->ResumeLayout(false);
			this->msMainMenu->PerformLayout();
			this->stStatus->ResumeLayout(false);
			this->stStatus->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private:
	System::Void EditItemDetails(System::Object^  sender, System::EventArgs^  e);
	System::Void NewConfiguration(System::Object^  sender, System::EventArgs^  e);
	System::Void OpenConfiguration(System::Object^  sender, System::EventArgs^  e);
	System::Void SaveConfiguration(System::Object^  sender, System::EventArgs^  e);

	System::Void CreateConfigurationView(parity::utils::Context& ctx);
	System::Void UpdateConfigurationView(parity::utils::Context& ctx);

	bool InitNewContext();

	parity::utils::Context* context_;
	parity::utils::Context* initial_;

public:
	static std::string MarshalSimpleStringToNative(String^ str);
	static String^ MarshalSimpleNativeToString(const std::string& str);
};
}
