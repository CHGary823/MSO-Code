<%@ Register TagPrefix="fckeditorv2" Namespace="FredCK.FCKeditorV2" Assembly="FredCK.FCKeditorV2" %>
<%@ Register TagPrefix="uc1" TagName="cpmenu" Src="../control/cpmenu.ascx" %>
<%@ Register TagPrefix="uc1" TagName="cptop" Src="../control/cptop.ascx" %>
<%@ Page language="c#" Codebehind="cpitem.aspx.cs" AutoEventWireup="false" Inherits="web.admin.cpitem" %>
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
														<TD style="WIDTH: 107px; HEIGHT: 36px" colSpan="2"><b>��Ʒ�����б�
																<asp:dropdownlist id="Dropdownlist2" runat="server" AutoPostBack="True"></asp:dropdownlist></b></TD>
													</TR>
													<TR>
														<TD colSpan="2">
															<asp:datagrid id="DataGrid1" runat="server" AutoGenerateColumns="False" Width="552px" AllowPaging="True"
																PageSize="40">
																<Columns>
																	<asp:BoundColumn DataField="id" HeaderText="��̖"></asp:BoundColumn>
																	<asp:BoundColumn DataField="name" HeaderText="���Q"></asp:BoundColumn>
																	<asp:BoundColumn DataField="type" HeaderText="���"></asp:BoundColumn>
																	<asp:BoundColumn DataField="gold" HeaderText="����"></asp:BoundColumn>
																	<asp:BoundColumn DataField="price" HeaderText="�[���"></asp:BoundColumn>
																	<asp:BoundColumn DataField="ItemID" HeaderText="��Ʒ��̖"></asp:BoundColumn>
																	<asp:BoundColumn DataField="buynum" HeaderText="����"></asp:BoundColumn>
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
														<TD align="left" style="WIDTH: 77px"><B>��Ʒ����</B></TD>
														<TD align="left"><FONT face="�����w">
																<asp:Label id="lblid" runat="server"></asp:Label></FONT></TD>
													</TR>
													<TR align="left">
														<TD align="left" style="WIDTH: 77px">��Ʒ���Q</TD>
														<TD align="left"><asp:textbox id="tbname" runat="server" Width="136px" Columns="80"></asp:textbox></TD>
													</TR>
													<TR align="left">
														<TD align="left" style="WIDTH: 77px">��ƷID</TD>
														<TD align="left"><asp:textbox id="tbitemid" runat="server" Width="120px" Columns="80"></asp:textbox></TD>
													</TR>
													<TR>
														<TD align="left" style="WIDTH: 77px">��Ʒ���</TD>
														<TD align="left"><asp:dropdownlist id="DropDownList1" runat="server"></asp:dropdownlist>
															<asp:RequiredFieldValidator id="RequiredFieldValidator2" runat="server" ErrorMessage="*" ControlToValidate="DropDownList1"></asp:RequiredFieldValidator></TD>
													</TR>
													<TR>
														<TD align="left" style="WIDTH: 77px">�[���</TD>
														<TD align="left">
															<asp:textbox id="tbprice" runat="server" Columns="10" Width="120px"></asp:textbox></TD>
													</TR>
													<TR>
														<TD style="WIDTH: 77px" align="left">����</TD>
														<TD align="left">
															<asp:textbox id="tbgold" runat="server" Columns="10" Width="120px"></asp:textbox></TD>
													</TR>
													<TR>
														<TD style="WIDTH: 77px" align="left">����</TD>
														<TD align="left"><FONT face="����">
																<asp:dropdownlist id="DropDownList3" runat="server">
																	<asp:ListItem Value="1">1</asp:ListItem>
																	<asp:ListItem Value="2">2</asp:ListItem>
																	<asp:ListItem Value="3">3</asp:ListItem>
																	<asp:ListItem Value="4">4</asp:ListItem>
																	<asp:ListItem Value="5">5</asp:ListItem>
																</asp:dropdownlist></FONT></TD>
													</TR>
													<TR>
														<TD align="left" style="WIDTH: 77px">�DƬ��ַ</TD>
														<TD align="left"><FONT face="����">
																<asp:textbox id="tbpic" runat="server" Width="176px" Columns="10">images/item/nopic.jpg</asp:textbox></FONT></TD>
													</TR>
													<TR>
														<TD align="left" style="WIDTH: 77px">��Ʒ�f��</TD>
														<TD align="left"><FONT face="����">
																<asp:textbox id="tbcomment" runat="server" Width="335px" Columns="10" Height="96px" TextMode="MultiLine"></asp:textbox></FONT></TD>
													</TR>
													<TR>
														<TD align="left" colspan="2"><FONT face="����"></FONT></TD>
													</TR>
													<TR>
														<TD align="center" colSpan="2">
															<asp:button id="btnedit" runat="server" Text="�� �� �� Ʒ" Visible="False"></asp:button><asp:button id="btnadd" runat="server" Text="�� �� �� Ʒ"></asp:button></TD>
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
