<%@ Page language="c#" Codebehind="cpnewstype.aspx.cs" AutoEventWireup="false" Inherits="web.admin.cpnewstype" %>
<%@ Register TagPrefix="uc1" TagName="cpmenu" Src="../control/cpmenu.ascx" %>
<%@ Register TagPrefix="uc1" TagName="cptop" Src="../control/cptop.ascx" %>
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
													<p><font color="#ff6633"><A href="../logout.aspx" target="_blank"><b><font color="#ff6666">�]�N�˳�</font></b></A></font></p>
												</div>
											</td>
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
											<td vAlign="top" align="left" height="350">
												<TABLE id="Table4" style="WIDTH: 384px; HEIGHT: 264px" cellSpacing="1" cellPadding="1"
													width="384" border="0">
													<TR>
														<TD style="WIDTH: 107px; HEIGHT: 22px" colSpan="2"><b>���������</b></TD>
													</TR>
													<TR>
														<TD colSpan="2">����б�[*ע:��̖�����޸�]</TD>
													</TR>
													<TR>
														<TD style="HEIGHT: 100px" colSpan="2"><FONT face="�����w"><asp:datagrid id="DataGrid1" runat="server" AutoGenerateColumns="False" Width="376px" AllowPaging="True"
																	PageSize="20">
																	<Columns>
																		<asp:BoundColumn DataField="id" HeaderText="��̖"></asp:BoundColumn>
																		<asp:BoundColumn DataField="name" HeaderText="���Q"></asp:BoundColumn>
																		<asp:BoundColumn DataField="used" HeaderText="�Ƿ�ʹ��"></asp:BoundColumn>
																		<asp:EditCommandColumn ButtonType="PushButton" UpdateText="����" HeaderText="����" CancelText="ȡ��" EditText="��݋"></asp:EditCommandColumn>
																		<asp:ButtonColumn Text="&lt;div id=&quot;de&quot; onclick=&quot;JavaScript:return confirm('�_���h����?')&quot;&gt;�h��&lt;/div&gt;"
																			HeaderText="�h��" CommandName="Delete"></asp:ButtonColumn>
																	</Columns>
																</asp:datagrid></FONT></TD>
													</TR>
													<TR>
														<TD align="left" colspan="2"><hr>
														</TD>
													</TR>
													<TR>
														<TD align="left"><B>���������</B></TD>
														<TD align="left"></TD>
													</TR>
													<TR align="left">
														<TD align="left">������������Q</TD>
														<TD align="left"><asp:textbox id="tbname" runat="server" Columns="16"></asp:textbox></TD>
													</TR>
													<TR>
														<TD align="left">�Ƿ���</TD>
														<TD align="left">
															<asp:RadioButton id="rbyes" runat="server" Text="��" GroupName="used" Checked="True"></asp:RadioButton>
															<asp:RadioButton id="rbno" runat="server" Text="��" GroupName="used"></asp:RadioButton></TD>
													</TR>
													<TR>
														<TD colspan="2" align="center"><asp:button id="btnadd" runat="server" Text="�� �� � ��"></asp:button></TD>
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
