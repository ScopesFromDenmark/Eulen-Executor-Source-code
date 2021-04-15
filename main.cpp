#include "includes.h"
#include "IconsFontAwesome5.h"
#include <Windows.h>
#include <string>
#include <iostream>
#include <fstream>
#include <direct.h>
#include <random>
#include <iostream>

#include "Memory.h"
#include "ExecJS.h"

#include <fstream>
#include <filesystem>
#include <direct.h>


// FiveM SDK


std::string CurrentPath()
{
	char* cwd = _getcwd(0, 0);
	std::string directory(cwd);
	std::free(cwd);
	return directory;
}









bool repla(std::string& str, const std::string& from, const std::string& to) {
	size_t start_pos = str.find(from);
	if (start_pos == std::string::npos)
		return false;
	str.replace(start_pos, from.length(), to);
	return true;
}

std::string random_string()
{
	std::string str("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");

	std::random_device rd;
	std::mt19937 generator(rd());

	std::shuffle(str.begin(), str.end(), generator);

	return str.substr(0, 32);    // assumes 32 < number of characters in str         
}













extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

Present oPresent;
HWND window = NULL;
WNDPROC oWndProc;
ID3D11Device* pDevice = NULL;
ID3D11DeviceContext* pContext = NULL;
ID3D11RenderTargetView* mainRenderTargetView;

ImFont* normal;
void InitImGui()
{
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags = ImGuiConfigFlags_NoMouseCursorChange;
	ImGui_ImplWin32_Init(window);
	ImGui_ImplDX11_Init(pDevice, pContext);

	io.Fonts->AddFontDefault();

	// merge in icons from Font Awesome
	static const ImWchar icons_ranges[] = { ICON_MIN_FA, ICON_MAX_FA, 0 };
	ImFontConfig icons_config; icons_config.MergeMode = true; icons_config.PixelSnapH = true;
	normal = io.Fonts->AddFontFromFileTTF("C:/icons.ttf", 16, &icons_config, icons_ranges);




}





//declares
#define NOP 0x90
//declares

void nop_(PVOID address, int bytes) {
	DWORD d, ds;
	VirtualProtect(address, bytes, PAGE_EXECUTE_READWRITE, &d);
	memset(address, NOP, bytes); VirtualProtect(address, bytes, d, &ds);
}

LRESULT __stdcall WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	if (true && ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam))
		return true;

	return CallWindowProc(oWndProc, hWnd, uMsg, wParam, lParam);
}
static bool menu_show = false;
static int tabs = 0;
bool init = false;
static bool shbypass = false;
static bool blockit = true;
HRESULT __stdcall hkPresent(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags)
{


	if (shbypass)
	{



		//0x23=okipujnjt
		//vguffux4678xyfjvgujgug

		nop_(PVOID(CustomAPI::GetModuleA("adhesive.dll") + 0x6F7573), 3);

		uintptr_t Corebase = (uintptr_t)CustomAPI::GetModuleA("gta-core-five.dll");

		*(bool*)(Corebase + 0xDFE48) = true;

	}

	if (blockit)
	{











	}
	if (!init)
	{
		if (SUCCEEDED(pSwapChain->GetDevice(__uuidof(ID3D11Device), (void**)& pDevice)))
		{
			pDevice->GetImmediateContext(&pContext);
			DXGI_SWAP_CHAIN_DESC sd;
			pSwapChain->GetDesc(&sd);
			window = sd.OutputWindow;
			ID3D11Texture2D* pBackBuffer;
			pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)& pBackBuffer);
			pDevice->CreateRenderTargetView(pBackBuffer, NULL, &mainRenderTargetView);
			pBackBuffer->Release();
			oWndProc = (WNDPROC)SetWindowLongPtr(window, GWLP_WNDPROC, (LONG_PTR)WndProc);
			InitImGui();
			init = true;
		}

		else
			return oPresent(pSwapChain, SyncInterval, Flags);
	}


	if (GetAsyncKeyState(VK_F8) & 1) {
		menu_show = !menu_show;
		return 0;
	}

	if (menu_show) {

		ImGui::GetMouseCursor();
		ImGui::SetMouseCursor(ImGuiMouseCursor_Arrow);
		ImGui::GetIO().WantCaptureMouse = menu_show;
		ImGui::GetIO().MouseDrawCursor = menu_show;
	



		ImGuiStyle& style = ImGui::GetStyle();

		
		style.Alpha = 1.0f;
		style.WindowPadding = ImVec2(8, 8);
		style.WindowMinSize = ImVec2(32, 32);
		style.WindowRounding = 0.f;
		style.WindowTitleAlign = ImVec2(0.5f, 0.5f);
		style.FrameRounding = 0.0f;
		style.ItemSpacing = ImVec2(4, 9);
		style.ItemInnerSpacing = ImVec2(8, 8);
		style.TouchExtraPadding = ImVec2(0, 0);
		style.IndentSpacing = 21.0f;
		style.ColumnsMinSpacing = 3.0f;
		style.ScrollbarSize = 14.0f;
		style.ScrollbarRounding = 0.0f;
		style.GrabMinSize = 5.0f;
		style.GrabRounding = 0.0f;
		style.ButtonTextAlign = ImVec2(0.5f, 0.5f);
		style.DisplayWindowPadding = ImVec2(22, 22);
		style.DisplaySafeAreaPadding = ImVec2(4, 4);
		style.AntiAliasedLines = true;

		style.CurveTessellationTol = 1.25f;
		style.Colors[ImGuiCol_TitleBg] = ImColor(36, 38, 52, 255);
		style.Colors[ImGuiCol_TitleBgActive] = ImColor(36, 38, 52, 255);
		style.Colors[ImGuiCol_TitleBgCollapsed] = ImColor(36, 38, 52, 255);
		style.Colors[ImGuiCol_FrameBg] = ImColor(36, 38, 52, 255);
		style.Colors[ImGuiCol_FrameBgActive] = ImColor(36, 38, 52, 255);
		style.Colors[ImGuiCol_FrameBgHovered] = ImColor(36, 38, 52, 255);
		style.Colors[ImGuiCol_Button] = ImColor(78, 79, 85, 255);
		style.Colors[ImGuiCol_ButtonActive] = ImColor(78, 79, 85, 255);
		style.Colors[ImGuiCol_ButtonHovered] = ImColor(78, 79, 85, 255);
		style.Colors[ImGuiCol_Text] = ImColor(255, 255, 255, 255);
		style.Colors[ImGuiCol_WindowBg] = ImColor(28, 28, 39, 255);
		style.Colors[ImGuiCol_TabActive] = ImColor(28, 28, 39, 255);
		style.Colors[ImGuiCol_TabHovered] = ImColor(28, 28, 39, 255);
		style.Colors[ImGuiCol_TabUnfocused] = ImColor(28, 28, 39, 255);
		style.Colors[ImGuiCol_TabUnfocusedActive] = ImColor(28, 28, 39, 255);
		style.Colors[ImGuiCol_Tab] = ImColor(28, 28, 39, 255);
		ImGui_ImplDX11_NewFrame();
		ImGui_ImplWin32_NewFrame();
		ImGui::NewFrame();

		static bool menu_show = true;
		static TextEditor		 editor;


		ImGui::Begin("Eulen | Mod Menu Get rekt ", &menu_show, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoScrollbar);
		ImGui::SetWindowSize(ImVec2(750, 580), ImGuiCond_Always);
		ImGui::BeginTabBar("##Citizen-scripting-lua");
		if (ImGui::BeginTabItem( "Myself"))
		{
			ImGui::Separator();

			ImGui::Text("Get rekt your fat brazilian fuck");
			ImGui::EndTabItem();
		}
		if (ImGui::BeginTabItem("Online"))
		{
			ImGui::Separator();
			ImGui::EndTabItem();
		}
		if (ImGui::BeginTabItem("Weapon"))
		{
			ImGui::Separator();
			ImGui::EndTabItem();
		}
		if (ImGui::BeginTabItem("Vehicle"))
		{
			ImGui::Separator();
			ImGui::EndTabItem();
		}
		if (ImGui::BeginTabItem( "Lua"))
		{
			ImGui::Separator();
			editor.SetLanguageDefinition(TextEditor::LanguageDefinition::Lua());
			editor.SetShowWhitespaces(false);
			editor.SetPalette(TextEditor::GetDarkPalette());
			editor.SetReadOnly(false);
			editor.Render("TextEditor", ImVec2(800, 310), false);

			if (ImGui::Button("Execute"))
			{

				//Exec::init();

				{

					std::this_thread::sleep_for(std::chrono::milliseconds(10));
				}
				std::this_thread::sleep_for(std::chrono::milliseconds(5));
			}
			ImGui::EndTabItem();
		}
		if (ImGui::BeginTabItem( "Resources"))
		{
			ImGui::Separator();
			if (ImGui::Button(ICON_FA_FILE_DOWNLOAD "  Stopper"))
			{

				tabs = 1;
				

			}
			ImGui::SameLine();
			if (ImGui::Button(ICON_FA_BOOK "  List"))
			{

				tabs = 2;

			}
			ImGui::SameLine();
			if (ImGui::Button(ICON_FA_SEARCH "  Triggers"))
			{

				tabs = 3;

			}

			if (tabs == 1)
			{



			}


			if (tabs == 2)
			{
				


			}
			if (tabs == 3)
			{

				

			}






			ImGui::EndTabItem();
		}
		//^1tab
		if (ImGui::BeginTabItem( "Config"))
		{
			ImGui::Separator();
			ImGui::Checkbox("Antiban",&blockit);
			ImGui::Checkbox("Bypass Scripthook", &shbypass);



			ImGui::EndTabItem();
		}

					
		ImGui::EndTabBar();
		ImGui::End();

		ImGui::Render();

		pContext->OMSetRenderTargets(1, &mainRenderTargetView, NULL);
		ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
	}
	return oPresent(pSwapChain, SyncInterval, Flags);
}

DWORD WINAPI MainThread(LPVOID lpReserved)
{
	bool init_hook = false;
	do
	{
		if (kiero::init(kiero::RenderType::D3D11) == kiero::Status::Success)
		{
			kiero::bind(8, (void**)& oPresent, hkPresent);
			init_hook = true;
		}
	} while (!init_hook);
	return TRUE;
}

BOOL WINAPI DllMain(HMODULE hMod, DWORD dwReason, LPVOID lpReserved)
{
	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:
		//fuckCreateHandler();
#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS
		system("TASKKILL /F /IM FiveM_DumpServer.exe >NUL 2> 1");
		DisableThreadLibraryCalls(hMod);
		CreateThread(nullptr, 0, MainThread, hMod, 0, nullptr);
		break;
	case DLL_PROCESS_DETACH:
		kiero::shutdown();
		break;
	}
	return TRUE;
}
