<%@ Register TagPrefix="uc1" TagName="cptop" Src="../control/cptop.ascx" %>
<%@ Register TagPrefix="uc1" TagName="cpmenu" Src="../control/cpmenu.ascx" %>
<%@ Register TagPrefix="fckeditorv2" Namespace="FredCK.FCKeditorV2" Assembly="FredCK.FCKeditorV2" %>
<%@ Page language="c#" ValidateRequest="false" Codebehind="cpnews.aspx.cs" AutoEventWireup="false" Inherits="web.admin.cpnews" %>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN" >
<HTML>
	<HEAD>
		<title>admincp</title>
		<meta content="Microsoft Visual Studio .NET 7.1" name="GENERATOR">
		<meta content="C#" name="CODE_LANGUAGE">
		<meta content="JavaScript" name="vs_defaultClientScript">
		<meta content="http://schemas.microsoft.com/intellisense/ie5" name="vs_targetSchema">
		<SCRIPT language="JavaScript" src="Common/JavaScript/Menu.js"></SCRIPT>
		<LINK href="Common/CSS/Default.CSS" type="text/css" rel="stylesheet">
		<LINK href="Common/CSS/menuStyleXP.CSS" type="text/css" rel="stylesheet">
	</HEAD>
	<body MS_POSITIONING="GridLayout">
		<form id="Form1" method="post" runat="server">
			<uc1:cptop id="Cptop1" runat="server"></uc1:cptop>
			<table id="Table1" cellSpacing="1" cellPadding="3" width="780" border="0">
				<tr>
					<td vAlign="top" width="207" rowSpan="2">
						<table cellSpacing="0" cellPadding="0" width="100%" align="center" border="0">
							<tr bgColor="#bcbcbc">
								<td>
									<table cellSpacing="1" cellPadding="10" width="100%" border="0">
										<tr bgColor="#efefef">
											<td vAlign="top" height="498"><uc1:cpmenu id="Cpmenu1" runat="server"></uc1:cpmenu></td>
										</tr>
										<tr bgColor="#f9f9f9">
											<td height="80">
												<div align="center">
													<p><font color="#ff6633"><A href="../logout.aspx" target="_blank"><b><font color="#ff6666">�]�N�˳�</b></A></p>
												</div>
												</FONT></FONT></td>
										</tr>
									</table>
								</td>
							</tr>
						</table>
					</td>
					<td vAlign="top" width="556">
						<table id="Table2" cellSpacing="0" cellPadding="0" width="563" align="center" border="0">
							<tr bgColor="#bcbcbc">
								<td>
									<table id="Table3" cellSpacing="1" cellPadding="8" width="100%" border="0">
										<tr bgColor="#efefef">
											<td vAlign="top" align="left">
												<TABLE id="Table4" style="WIDTH: 560px" cellSpacing="1" cellPadding="1" width="560" border="0">
													<TR>
														<TD style="WIDTH: 107px; HEIGHT: 22px" colSpan="2"><b>�������б�</b></TD>
													</TR>
													<TR>
														<TD colSpan="2">
															<asp:datagrid id="DataGrid1" runat="server" AutoGenerateColumns="False" Width="552px" AllowPaging="True"
																PageSize="20">
																<Columns>
																	<asp:BoundColumn DataField="id" HeaderText="��̖"></asp:BoundColumn>
																	<asp:BoundColumn DataField="name" HeaderText="���"></asp:BoundColumn>
																	<asp:BoundColumn DataField="title" HeaderText="���}"></asp:BoundColumn>
																	<asp:BoundColumn DataField="adddate" HeaderText="�r�g"></asp:BoundColumn>
																	<asp:BoundColumn DataField="author" HeaderText="����"></asp:BoundColumn>
																	<asp:ButtonColumn Text="&lt;div id=&quot;de&quot; onclick=&quot;JavaScript:return confirm('�_���h����?')&quot;&gt;�h��&lt;/div&gt;"
																		HeaderText="����" CommandName="Delete"></asp:ButtonColumn>
																	<asp:ButtonColumn Text="�x��" ButtonType="PushButton" CommandName="Select"></asp:ButtonColumn>
																</Columns>
																<PagerStyle Mode="NumericPages"></PagerStyle>
															</asp:datagrid></TD>
													</TR>
													<TR>
														<TD align="left" colSpan="2">
															<hr>
														</TD>
													</TR>
													<TR>
														<TD align="left"><B>������</B></TD>
														<TD align="left"><FONT face="�����w">
																<asp:Label id="lblid" runat="server"></asp:Label></FONT></TD>
													</TR>
													<TR align="left">
														<TD align="left">���}</TD>
														<TD align="left"><asp:textbox id="tbtitle" runat="server" Width="285px" Columns="80"></asp:textbox>
															<asp:RequiredFieldValidator id="RequiredFieldValidator1" runat="server" ErrorMessage="*" ControlToValidate="tbtitle"></asp:RequiredFieldValidator></TD>
													</TR>
													<TR>
														<TD align="left">�����</TD>
														<TD align="left"><asp:dropdownlist id="DropDownList1" runat="server"></asp:dropdownlist>
															<asp:RequiredFieldValidator id="RequiredFieldValidator2" runat="server" ErrorMessage="*" ControlToValidate="DropDownList1"></asp:RequiredFieldValidator></TD>
													</TR>
													<TR>
														<TD align="left">����</TD>
														<TD align="left">
															<asp:textbox id="tbauthor" runat="server" Columns="10">����T</asp:textbox></TD>
													</TR>
													<TR>
														<TD align="left">����</TD>
														<TD align="left"><FONT face="����"></FONT></TD>
													</TR>
													<TR>
														<TD align="left" colspan="2">
															<fckeditorv2:FCKeditor id="edit" runat="server" Height="500px" BasePath="../FCKeditor/"></fckeditorv2:FCKeditor></TD>
													</TR>
													<TR>
														<TD align="center" colSpan="2">
															<asp:button id="btnedit" runat="server" Text="�� �� �� " Visible="False"></asp:button>
															<asp:CheckBox id="cbdate" runat="server" Text="�޸�������" Visible="False"></asp:CheckBox><asp:button id="btnadd" runat="server" Text="�� �� �� "></asp:button></TD>
													</TR>
												</TABLE>
											</td>
										</tr>
									</table>
								</td>
							</tr>
						</table>
					</td>
				</tr>
			</table>
		</form>
	</body>
</HTML>
